#include "sort.h"

/**
 * swap - swaps two elements of an array
 *
 * @small: the smallest element
 * @large: the element at the first index
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
