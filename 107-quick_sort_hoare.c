#include "sort.h"

/**
 * hoare_partition - partitions array based on the Hoare's partition algorithm
 *
 * @array: the array to partition
 * @start: the starting index
 * @end: the end index
 *
 * Return: the pivot
 */

int hoare_partition(int *array, int start, int end)
{
	int size = end + 1;
	int pivot = array[end];
	int i = start - 1;
	int j;
	int temp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;	/* increment index of smaller element */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	print_array(array, size);
	
	return (i + 1);
}

/**
 * hoare_quick_sort - implements the Hoare's algorithm
 *
 * @array: the array to sort
 * @start: starting indes
 * @end: ending index
 *
 * Return: Nothing
 */

void hoare_quick_sort(int *array, int start, int end)
{
	if (start < end)
	{
		/* partition is the partitioning index */
		int partition = hoare_partition(array, start, end);

		/* separately sort the left and the right partitions */
		hoare_quick_sort(array, start, partition - 1);
		hoare_quick_sort(array, partition + 1, end);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	size_t end;

	end = size - 1;

	hoare_quick_sort(array, 0, end);
}

