#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, position;

	/* Traverse unsorted subarray one by one and find minimu element */
	for (i = 0; i < size - 1; i++)
	{
		position = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[position])			
				position = j;
		}
		/* if less than value at min index(position), swap with current min value i*/
		if (position != i)
		{
			swap(&array[position], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps elements of an array
 *
 * @mall: small element
 * @large: large element
 *
 * Return: Nothing
 */

void swap(int *small, int *large)
{
	int temp;

	temp = *small;
	*small = *large;
	*large = temp;
}
