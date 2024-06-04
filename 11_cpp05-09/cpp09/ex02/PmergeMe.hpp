#pragma once
#ifndef __P_MERGE_ME_H__
#define __P_MERGE_ME_H__

#include <ctime>
#include <deque>
#include <vector>
#include <utility>
#include <cstdlib>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(char const * const strs[], long const & size);
	PmergeMe(PmergeMe const & org);
	~PmergeMe();
	PmergeMe & operator = (PmergeMe const & org);
	bool isSorted(void) const;
	void printArr(void) const;
	void printTime(char const * const type) const;

	template <typename C, typename P>
	void sort(void)
	{
		clock_t start, end;
		C con;
		P pairs;

		con.clear();
		start = clock();
		this->setPairs<C, P>(con, pairs);
		merge<P>(pairs.begin(), pairs.end());
		con.push_back(pairs[0].second);
		con.push_back(pairs[0].first);
		insert<C, typename P::iterator>(con, pairs.begin(), pairs.end(), 1);
		if (this->mSize % 2 == 1)
		{
			std::size_t toInsert = search<C>(con, this->mArr[this->mSize - 1]);
			con.insert(con.begin() + toInsert, this->mArr[this->mSize - 1]);
		}
		for (std::size_t index = 0; index < this->mSize; index++)
		{
			this->mArr[index] = con[index];
		}
		end = clock();
		this->mTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	}
private:
	unsigned int * mArr;
	std::size_t mSize;
	double mTime;

	static unsigned long getJacopsthal(std::size_t const& index);

	template <typename C, typename P>
	void setPairs(C const & c, P & pairs)
	{
		long size = (c.size() % 2 == 0 ? this->mSize : this->mSize - 1);
		for (std::size_t index = 1; index < static_cast<std::size_t>(size); index += 2)
		{
			unsigned int big = (this->mArr[index - 1] < this->mArr[index] ? this->mArr[index] : this->mArr[index - 1]);
			unsigned int small = (this->mArr[index - 1] >= this->mArr[index] ? this->mArr[index] : this->mArr[index - 1]);
			pairs.push_back(std::make_pair(big, small));
		}
	}

	template <typename C>
	static std::size_t search(C & c, unsigned int const& num)
	{
		int first, mid, last;
		first = 0;
		last = static_cast<unsigned int>(c.size()) - 1;
		while (first < last)
		{
			mid = first + (last - first) / 2;
			if (num == c[mid])
			{
				return mid;
			}
			else if (num < c[mid])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		return static_cast<std::size_t>(num < c[first] ? first : first + 1);
	}

	template <typename C>
	static void merge(typename C::iterator start, typename C::iterator end)
	{
		std::size_t dist = std::distance(start, end);
		if (dist <= 1)
		{
			return;
		}
		else if (dist == 2)
		{
			if (*start > *(start + 1))
			{
				std::swap(*start, *(start + 1));
			}
			return;
		}

		typename C::iterator mid = start + dist / 2;
		merge<C>(start, mid);
		merge<C>(mid, end);

		C tmp;
		typename C::iterator i, j;
		i = start;
		j = mid;
		while (i != mid && j != end)
		{
			if (*i <= *j)
			{
				tmp.push_back(*i);
				i++;
			}
			else
			{
				tmp.push_back(*j);
				j++;
			}
		}

		if (i == mid)
		{
			while (j != end)
			{
				tmp.push_back(*j);
				j++;
			}
		}
		else
		{
			while (i != mid)
			{
				tmp.push_back(*i);
				i++;
			}
		}

		typename C::iterator orgIt = start;
		typename C::iterator tmpIt = tmp.begin();
		while (orgIt != end && tmpIt != tmp.end())
		{
			*orgIt = *tmpIt;
			orgIt++;
			tmpIt++;
		}
	}

	template <typename C, typename P>
	static void insert(C & c, P start, P end, std::size_t const& index)
	{
		std::size_t dist = std::distance(start, end);
		if (dist <= 1)
		{
			return;
		}
		unsigned long jacopNum = getJacopsthal(index);
		jacopNum = (jacopNum < dist ? jacopNum : dist - 1);
		std::size_t toInsert;
		for (P it = start + jacopNum; it != start; it--)
		{
			toInsert = search<C>(c, it->second);
			c.insert(c.begin() + toInsert, it->second);
			toInsert = search<C>(c, it->first);
			c.insert(c.begin() + toInsert, it->first);
		}
		insert<C, P>(c, start + jacopNum, end, index + 1);
	}
};


#endif