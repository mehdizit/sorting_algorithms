#include "sort.h"
/**
 * partition - this partitions the array and swaps
 * @array: input array
 * @lb: input low index
 * @ub: input high index
 * @size: input size of array
 * Return: return the partioned index
 */

int partition(int *array, int lb, int ub, size_t size)
{
	int pivot, start, end, tmp;

	pivot = array[ub];
	start = lb - 1;
	end = lb;
	while (end < ub)
	{
		if (array[end] <= pivot)
		{
			start++;
			if (start != end)
			{
				tmp = array[start];
				array[start] = array[end];
				array[end] = tmp;
				print_array(array, size);
			}
		}
		end++;
	}
	if (pivot < array[start + 1])
	{
		tmp = array[start + 1];
		array[start + 1] = array[ub];
		array[ub] = tmp;
		print_array(array, size);
	}
	return (start + 1);
}
/**
* quick_sort_m - sorting the array using recursion
* @array: input array
* @lb: input low index
* @ub: input high index
* @size: input size of array
*/
void quick_sort_m(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub, size);
		quick_sort_m(array, lb, loc - 1, size);
		quick_sort_m(array, loc + 1, ub, size);
	}
}
/**
 * quick_sort - sory array using quick sort method
 * @array: input array
 * @size: input size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t lb, ub;

	if (array == NULL || size < 2)
		return;
	lb = 0;
	ub = size - 1;
	quick_sort_m(array, lb, ub, size);
}
