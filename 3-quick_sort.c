#include "sort.h"

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
	int i = (low - 1);
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
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
