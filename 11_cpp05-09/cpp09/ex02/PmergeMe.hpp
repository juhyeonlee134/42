#pragma once
#ifndef __P_MERGE_ME_H__
#define __P_MERGE_ME_H__

#include <string>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(char** strs, std::size_t const& size);
	PmergeMe(PmergeMe const& org);
	~PmergeMe(void);
	PmergeMe& operator = (PmergeMe const& org);
	void sort(void);
    void printArr(void) const;
    bool isSorted(void) const;
private:
	unsigned int* mArr;
	std::size_t mSize;

	unsigned long getJacopsthal(std::size_t const& index);

	template <typename C, typename P>
	void setPairs(C const& c, P& p)
	{
		for (std::size_t index = 0; index < c.size(); index += 2)
		{
			unsigned int big = (c[index] >= c[index + 1] ? c[index] : c[index + 1]);
			unsigned int small = (c[index] < c[index + 1] ? c[index] : c[index + 1]);
			std::pair<unsigned int, unsigned int> tmp = std::make_pair(big, small);
			p.push_back(tmp);
		}
	}

	template <typename C>
	void merge(typename C::iterator start, typename C::iterator end)
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

	template <typename C>
	std::size_t search(C& c, unsigned int const& num)
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

	template <typename C, typename P>
	void insert(C& c, P start, P end, std::size_t const& index)
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