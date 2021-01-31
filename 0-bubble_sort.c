#include "sort.h"
/**
 * bubble_sort - sort using bubble sort method
 * @array: array of list
 * @size: the size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
