#include "sort.h"

/**
 * copy_array - copies elements of an array into another array
 *
 * @array: the array to copy elements from
 * @start: the initial index to start copying
 * @end: the last index to end copying
 * @array_copy: the array to copy elements into
 *
 * Return: Nothing
 */

void copy_array(int *array, size_t start, size_t end, int *array_copy)
{
	size_t i;

	for (i = start; i < end; i++)
		array_copy[i] = array[i];
}

/**
 * top_down_merge - splits and merges arrays
 *
 * @array: the array to split
 * @start: the starting index
 * @mid: the mid index
 * @end: the end index
 * Description: left source half is array[start:mid-1]
 * right source half is array[mid:end-1]
 * copy array result is array_coppy[start:end-1]
 * Return: Nothing
 */

void top_down_merge(int *array, size_t start,
	       size_t mid, size_t end, int *array_copy)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	i = start;
	j = mid;

	/* while there are elements in the left of right runs... */
	for (k = start; k < end; k++)
	{
		/* if left run head exists and is <= existing right run head */
		if (i < mid && (j >= end || array[i] <= array[j]))
	       	{
			array_copy[k] = array[i];
		       	i++;
		}
	       	else
	       	{
			array_copy[k] = array[j];
		       	j++;
	       	}
	}
       	printf("[Done]: ");
	print_array(array_copy + start, end - start);
}

/**
 * top_down_split_merge - splits array into 2 halves,
 * sorts both halves into array_copy
 * and merges the halves from array_copy to array
 * @array_copy: the working array
 * @start: the starting index (inclusive)
 * @end: the end index (exclusive)
 * @array: the source array
 *
 * Return: Nothing
 */

void top_down_split_merge(int *array_copy,
	       size_t start, size_t end, int *array)
{
	size_t mid;

	/* if array only has one element, it is sorted */
	if (end - start <= 1)
		return;

	/* if array has more than 1 element, split it into halves */
	mid = (end + start) / 2;

	/* recursively sort both halves from array to array_coppy */
	top_down_split_merge(array, start, mid, array_copy);
	top_down_split_merge(array, mid, end, array_copy);

	/* merge resulting halves from array_copy into array */
	top_down_merge(array_copy, start, mid, end, array);
}

/**
 * merge_sort - sorts an array using the top down merge sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array to sort
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *array_copy;
	/* size_t i; */

	if (array == NULL || size <= 1)
		return;

	array_copy = malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return;

	/* for (i = 0; i < size; i++) */
		/* array_copy[i] = array[i]; */
	copy_array(array, 0, size - 1, array_copy);
	top_down_split_merge(array_copy, 0, size, array);
	free(array_copy);
}
