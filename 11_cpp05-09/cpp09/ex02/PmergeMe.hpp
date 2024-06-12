#pragma once
#ifndef __P_MERGE_ME_H__
#define __P_MERGE_ME_H__

#include <ctime>
#include <iostream>

typedef int idx_t;

class PmergeMe
{
public:
	PmergeMe(char const* const strs[], int const size);
	PmergeMe(PmergeMe const& org);
	~PmergeMe();
	PmergeMe& operator=(PmergeMe const& org);
	void printArr(void) const;
	void isSorted(void) const;
	void checkSame(PmergeMe const& other);
	void printTime(char const* const type) const;

	template <typename C>
	void sort(void)
	{
		C c;
		for (int index = 0; index < this->mSize; index++)
		{
			c.push_back(this->mArr[index]);
		}
		if (!isSorted<C>(c))
		{
			clock_t start = clock();
			fordJohnson<C>(c, 1);
			clock_t end = clock();
			this->mTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
		}
		for (int index = 0; index < this->mSize; index++)
		{
			this->mArr[index] = c[index];
		}
	}


private:
	int* mArr;
	int mSize;
	double mTime;

	PmergeMe();
	int jacobsthal(int const n);

	template <typename C>
	idx_t search(C const c, int const size, int const toFind, std::size_t const span)
	{
		idx_t first = 0, last = size - 1;
		
		while (first < last)
		{
			idx_t mid = first + (last - first) / 2;
			if (toFind == c[span * mid])
			{
				return mid;
			}
			else if (toFind < c[span * mid])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		if (first == last)
		{
			return (toFind <= c[span * first] ? first : first + 1);
		}
		return (toFind <= c[span * first] ? first : first + 1);
	}

	template <typename C>
	bool isSorted(C const c)
	{
		for (std::size_t index = 1; index < c.size(); index++)
		{
			if (c[index - 1] > c[index])
			{
				return false;
			}
		}
		return true;
	}

	template <typename C>
	void swap(C& c, idx_t const idx, std::size_t const span)
	{
		for (std::size_t cnt = 0; cnt < span; cnt++)
		{
			int tmp = c[span * idx + cnt];
			c[span * idx + cnt] = c[span * (idx - 1) + cnt];
			c[span * (idx - 1) + cnt] = tmp;
		}
	}

	template <typename C>
	void push(C& d, C& o, idx_t const idx, std::size_t const span)
	{
		for (std::size_t cnt = 0; cnt < span; cnt++)
		{
			d.push_back(o[span * idx]);
			o.erase(o.begin() + span * idx);
		}
	}

	template <typename C>
	void insert(C& d, idx_t const dIdx, C& o, idx_t const oIdx, std::size_t const span)
	{
		for (std::size_t cnt = 0; cnt < span; cnt++)
		{
			d.insert(d.begin() + span * dIdx + cnt, o[span * oIdx]);
			o.erase(o.begin() + span * oIdx);
		}
	}

	template <typename C>
	void moveAll(C& d, C& o)
	{
		while (!o.empty())
		{
			d.push_back(o[0]);
			o.erase(o.begin());
		}
	}

	template <typename C>
	void fordJohnson(C& c, std::size_t const span)
	{
		if (2 * span >= c.size())
		{
			return;
		}
		for (idx_t index = 1; index < static_cast<idx_t>(c.size() / span); index += 2)
		{
			if (c[span * (index - 1)] < c[span * index])
			{
				swap<C>(c, index, span);
			}
		}
		fordJohnson(c, 2 * span);

		std::cout << std::endl << "span : " << span << std::endl;
		for (std::size_t index = 0; index < c.size(); index++)
		{
			if (index % span == 0)
				std::cout << "| ";
			std::cout << c[index] << ' ';
		}

		C big, small;
		idx_t idx = (c[0] <= c[span] ? 0 : 1);
		push<C>(big, c, idx, span);
		push<C>(big, c, 0, span);

		std::size_t size = c.size() / span / 2;

		for (std::size_t cnt = 0; cnt < size; cnt++)
		{
			push<C>(big, c, 0, span);
			push<C>(small, c, 0, span);
			std::cout << cnt << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl << "big : ";
		for (std::size_t index = 0; index < big.size(); index++)
		{
			if (index % span == 0)
				std::cout << "| ";
			std::cout << big[index]<< ' ';
		}
		std::cout << std::endl;
		std::cout << "small : ";
		for (std::size_t index = 0; index < small.size(); index++)
		{
			if (index % span == 0)
				std::cout << "| ";
			std::cout << small[index] << ' ';
		}
		std::cout << std::endl;

		int n = 3, pJnum = 1, sortedSize = 2;
		while (!small.empty())
		{
			int jnum = jacobsthal(n);
			int last = (jnum - pJnum <= static_cast<int>(small.size() / span) ? jnum - pJnum : small.size() / span) - 1;
			for (idx_t index = last; index >= 0; index--)
			{
				idx_t toInsert = search<C>(big, sortedSize + last, small[span * index], span);
				std::cout << "to insert : " << toInsert << std::endl;
				insert<C>(big, toInsert, small, index, span);
			}
			sortedSize += (2 * last);
			pJnum = jnum;
			n++;
		}
		if (c.size() >= span)
		{
			idx_t toInsert = search<C>(big, big.size() / span, c[0], span);
			insert<C>(big, toInsert, c, 0, span);
		}
		moveAll(big, c);
		moveAll(c, big);

		std::cout << "ret : ";
		for (std::size_t index = 0; index < c.size(); index++)
		{
			if (index % span == 0)
				std::cout << "| ";
			std::cout << c[index] << ' ';
		}
		std::cout << std::endl << std::endl;
	}
/*
		C tmp;
		idx_t idx = (c[0] <= c[span] ? 0 : 1);
		push<C>(tmp, c, idx, span);
		push<C>(tmp, c, 0, span);
		int n = 3;
		while (c.size() >= 2 * span)
		{
			idx_t jnum = jacobsthal(n);
			jnum = (jnum <= static_cast<idx_t>(c.size() / span / 2) ? jnum : c.size() / span / 2);
			for (int cnt = 0; cnt < jnum; cnt++)
			{
				push<C>(tmp, c, cnt, span);
			}
			for (idx_t index = jNum - 1; index >= 0; index--)
			{
				idx_t toInsert = search<C>(tmp, c[span * index], span);
				insert<C>(tmp, toInsert, c, index, span);
			}
			n++;
		}
		if (c.size() >= span)
		{
			idx_t toInsert = search<C>(tmp, c[0], span);
			insert<C>(tmp, toInsert, c, 0, span);
		}
		moveAll<C>(tmp, c);
		moveAll<C>(c, tmp);
	}
*/
};

#endif

// 97 76 90 46 54 53 40 3 96 18 70 22 84 13 77 26 94 43 67 24 87 63 71 59 82 37 61 20 68 12 25 9 
// 99 73 49 4 74 29 39 33 98 52 80 28 93 60 17 14 86 1 65 44 79 38 56 36 83 6 21 15 58 42 27 10 
// 100 95 92 72 62 31 57 48 88 32 85 5 55 8 50 7 89 11 41 19 66 30 51 4578 2 35 23 75 64 47 34 
// 91 81 69 16 
