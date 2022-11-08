#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, swapped;

	do {
		swapped	= 0;
		for (i = 0; i < size - 1; i++)
		{
			/* if first element is greater than its next, swap */
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);

				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped);
}


/**
 * swap - swaps elements of an array
 *
 * @small: small element
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
