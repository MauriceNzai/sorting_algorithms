#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	unsigned int i, temp, swapped;

	do {
		swapped	= 0;
		for (i = 0; i < size - 1; i++)
		{
			/* if first element is greater than its next, swap */
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1; 
				print_array(array, size);
			}
		}
	} while (swapped); 
}
