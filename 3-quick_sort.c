#include "sort.h"

/**
 * _swap - Swaps two values.
 * @a: First value.
 * @b: Second value.
 * Return: void.
 */
void _swap(int *a, int *b)
{
int temp = *a;/* Store the value of 'a' in a temporary variable */
*a = *b;/* Assign the value of 'b' to 'a' */
*b = temp;/* Assign the temporary value to 'b' */
}

/**
 * lomuto - Lomuto partition.
 * @array: Pointer to the array to partition.
 * @size: Size of the array.
 * @low: The lowest index.
 * @high: The highest index.
 * Return: Pivot index.
 */
int lomuto(int *array, size_t size, int low, int high)
{
int i, j, pivot = array[high];  /* Initialize pivot */

i = low - 1;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;  /* Increment 'i' when a smaller element is found */
if (array[i] != array[j])
{
_swap(&array[i], &array[j]);  /* Swap elements */
print_array(array, size);  /* Print the array after each swap */
}
}
}

if (array[i + 1] != array[high])
{
_swap(&array[i + 1], &array[high]);  /* Swap elements */
print_array(array, size);  /* Print the array after the final swap */
}

return (i + 1);  /* Return the pivot index */
}

/**
 * _quick_sort - Sort a portion of the array.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @low: The lowest index.
 * @high: The highest index.
 * Return: void.
 */
void _quick_sort(int *array, size_t size, int low, int high)
{
if (low < high)
{
int mid = lomuto(array, size, low, high);/* Find the pivot */

_quick_sort(array, size, low, mid - 1);/* Sort left partition */
_quick_sort(array, size, mid + 1, high);/* Sort right partition */
}
}

/**
 * quick_sort - Implement the quick sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;/* Return if the array is empty */

_quick_sort(array, size, 0, size - 1);/* Call sorting funct */
}

