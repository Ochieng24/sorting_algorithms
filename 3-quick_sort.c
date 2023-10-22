#include "sort.h"
/**
  * _swap - swap two values
  * @a: first value
  * @b: second value
  * Return: void
  */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
  * lomuto - partition
  * @low: the lowest index
  * @high: the highest index
  * @array: pointer to array of list to partion
  * @size: size of array
  * Return: pivot index
  */
int lomuto(int *array, size_t size, int low, int high)
{
	/* initialize pivot*/
	int i, j, pivot = array[high];

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
  * _quick_sort - sort portion of array and divide into partion and sort
  * @array: pointer to array of list to partion
  * @low: the lowest index
  * @high: the highest index
  * @size: size of array
  * Return: void
  */
void _quick_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int mid = lomuto(array, size, low, high);

		_quick_sort(array, size, low, mid - 1);
		_quick_sort(array, size, mid + 1, high);
	}
}

/**
  * quick_sort - implement the sort
  * @array: pointer to array of list to portion
  * @size: size of the array
  * Return: void
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort(array, size, 0, size - 1);
}
