#include "sort.h"

/**
 *_swap - swaps two intergers
 *@a: value 1
 *@b: value 2
 */
void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *bubble_sort - sorts an array of intergers in ascending order
 *@array: array to sort
 *@size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int count = 0;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			_swap(&array[i], &array[i + 1]);
			count++;
			print_array(array, size);
		}
	}
	if (count == 0)
		return;

	bubble_sort(array, size);
}
