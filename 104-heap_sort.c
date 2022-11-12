#include "sort.h"

/**
 * max - determines the largest value of the array
 *
 * @array: the array in which to find max value
 * @size: the size of the array
 * @i: iterator
 * @j: iterator
 * @k: iterator
 *
 * Return: the larges element of the array
 */

int max(int *array, size_t size, size_t i, size_t j, size_t k)
{
	size_t largest;

	largest	= i;
	if (j < size && array[j] > array[largest])
	{
		largest = j;
	}
	if (k < size && array[k] > array[largest])
	{
		largest = k;
	}
	return (largest);
}

/**
 * sift_down_heap - heapify the array using siftdown algorithm
 *
 * @array: the array to heapify
 * @size: the size of the array
 * @i: the iterator
 *
 * Return: Nothing
 */

void sift_down_heap(int *array, size_t size, size_t i)
{
	size_t j;
	int temp;

	while (1)
	{
		j = max(array, size, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
		{
			break;
		}
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i = j;
		print_array(array, size);
	}
}

/**
 * heap_sort - sorts an array of integers using the heap sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array to sort
 *
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	for (i = (size - 2) / 2; i >= 0; i--)
	{
		sift_down_heap(array, size, i);
	}
	for (i = 0; (unsigned int) i < size; i++)
	{
		temp = array[size - i - 1];
		array[size - i - 1] = array[0];
		array[0] = temp;
		sift_down_heap(array, size - i - 1, 0);
		print_array(array, size);
	}
}
