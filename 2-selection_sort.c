#include "sort.h"
/**
 *_swap - swaps two values of type int
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
 *selection_sort - algo that sorts an array of ints in ascending order
 *@array: array to sort
 *@size: length of array to sort
 */
void selection_sort(int *array, size_t size)
{
	size_t j, i, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			_swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
