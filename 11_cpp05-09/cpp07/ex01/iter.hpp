#pragma once
#ifndef __ITER_H__
#define __ITER_H__

template <typename T>
void iter(T * arr, int len, void (*func)(T &))
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

#endif