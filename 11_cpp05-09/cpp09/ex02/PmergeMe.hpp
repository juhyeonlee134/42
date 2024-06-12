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
	idx_t search(C const c, int const toFind, std::size_t const span)
	{
		idx_t first = 0, last = c.size() / span - 1;
		
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

		C big, small, sorted;
		idx_t idx = (c[0] <= c[span] ? 0 : 1);
		push<C>(sorted, c, idx, span);
		push<C>(sorted, c, 0, span);

		std::size_t size = c.size() / span / 2;
		for (std::size_t cnt = 0; cnt < size; cnt++)
		{
			push<C>(big, c, 0, span);
			push<C>(small, c, 0, span);
		}

		int n = 3, pJnum = 1;
		while (!small.empty())
		{
			int jnum = jacobsthal(n);
			int last = (jnum - pJnum <= static_cast<int>(small.size() / span) ? jnum - pJnum : small.size() / span) - 1;
			for (idx_t index = 0; index <= last; index++)
			{
				push<C>(sorted, big, 0, span);
			}
			for (idx_t index = last; index >= 0; index--)
			{
				idx_t toInsert = search<C>(sorted, small[span * index], span);
				insert<C>(sorted, toInsert, small, index, span);
			}
			pJnum = jnum;
			n++;
		}
		if (c.size() >= span)
		{
			idx_t toInsert = search<C>(sorted, c[0], span);
			insert<C>(sorted, toInsert, c, 0, span);
		}
		moveAll(sorted, c);
		moveAll(c, sorted);
	}
};

#endif