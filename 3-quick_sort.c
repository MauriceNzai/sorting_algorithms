#include "sort.h"

/**
 * swap - swaps elements of an array
 * @small: small element
 * @large: large element
 * Return: Nothing
 */
void swap(int *small, int *large)
{
	int temp;

	temp = *small;
	*small = *large;
	*large = temp;
}
/**
 * lomuto_partition - partitions the given array based on lamuto algorithm
 * @array: the array to partition
 * @low: the lower index of any given two elements
 * @high: the higher index of any given two elements
 * @size: the size of the array
 * Return: i/the pivot elements
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
/**
* q_sort - sorts an array of integers partitions based on lamuto algorithm
* @array: the array to partition
* @low: the lower index of any given two elements
* @high: the higher index of any given two elements
* @size: the size of the array
* Return: nothing
*/
void q_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		q_sort(array, low, pivot - 1, size);
		q_sort(array, pivot + 1, high, size);
	}
}
/**
* quick_sort - sorts an array of integers in ascending order
* @array: the array to sort
* @size: size of the given array
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
