#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two values of an array
 * @array: given array
 * @i: first element's index
 * @j: second element's index
 *
 * Return: void
 */
void swap(int *array, long int i, long int j)
{
	int tmp;

	if (!array)
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * shell_sort - sorts array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Description: this function sorts an array of integers
 * in increasing order using the Shell sort algorithm
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	long int h, i, j;

	h = 1;
	while ((size_t)h <= (size - 1) / 9)
		h = (h * 3) + 1;

	while (h >= 1)
	{
		printf("h: %li\n", h);
		for (j = h; (size_t)j < size; j++)
		{
			for (i = j - h; i >= 0; i -= h)
			{
				if (array[i] > array[i + h])
					swap(array, i, i + h);
				else
					break;
			}
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
