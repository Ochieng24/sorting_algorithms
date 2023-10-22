#include "sort.h"
/**
 * _swap - Swaps two integer values.
 * @a: First value to swap.
 * @b: Second value to swap.
 */
void _swap(int *a, int *b)
{
int temp;  /* Temporary variable */

temp = *a;  /* Store the value of 'a' in 'temp' */
*a = *b;    /* Assign 'b' to 'a' */
*b = temp;  /* Assign 'temp' to 'b' */
}

/**
 * selection_sort - Sorts an array of integer.
 * @array: Array to sort.
 * @size: Length of the array to sort.
 */
void selection_sort(int *array, size_t size)
{
size_t j, i, min;/* Loop variables and minimum index */

for (i = 0; i < size - 1; i++)
{
min = i;/* Assume the current index is the minimum */
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min])
{
min = j;/* Update minimum index */
}
}
if (min != i)
{
_swap(&array[i], &array[min]);/* Swap elements if necessary */
print_array(array, size);/* Print the array after each swap */
}
}
}
