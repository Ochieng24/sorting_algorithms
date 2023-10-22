
#include "sort.h"

/**
 * _swap - Swaps two integers.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void _swap(int *a, int *b)
{
int temp;  /* Temporary variable to hold 'a' */

temp = *a;  /* Store the value of 'a' in 'temp' */
*a = *b;    /* Assign 'b' to 'a' */
*b = temp;  /* Assign 'temp' to 'b' */
}

/**
 * bubble_sort - Sorts an array of int ascending order.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t i;    /* Loop variable */
int count = 0;  /* Count of swaps */

if (size < 2)
return;  /* If size is less than 2, no need to sort */

for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
_swap(&array[i], &array[i + 1]);  /* Swap elements */
count++;  /* Increment the swap count */
print_array(array, size);  /* Print the array after each swap */
}
}

if (count == 0)
return;  /* If no swaps were made, the array is already sorted */

bubble_sort(array, size);/* Recursively call bubble_sort*/
}
