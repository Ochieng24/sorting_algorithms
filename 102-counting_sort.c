#include "sort.h"
/**
 *_max- returns the largest number in the array
 *@array: array to get max of
 *@size: size of the array
 *Return: largest number
 **/
int _max(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 *counting_sort - Implementation of the counting sort algo
 *@array: array to be sorted
 *@size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = _max(array, size);
	int i;
	int *count = malloc((max + 1) * sizeof(int));
	int *output = malloc(size * sizeof(int));

	if (array == NULL || size < 2 || output == NULL || count == NULL)
	{
		return;
	}

	/** Initialize count array elements to 0 **/
	for (i = 0; i < (max + 1); i++)
	{
		count[i] = 0;
	}

	/**
	 *Build the count array based on number of occurence
	 *of an element aganist its index. If 2 occurs 3x place 3 at count[3]
	 **/
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}

	/**
	 *Update count array to contain the total indexes occupied for each
	 *element in consecutive order
	 **/
	for (i = 1; i < (max + 1); i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, max + 1);

	/**
	 *Build the output array. Use the Updated count to determine the
	 *position of each element in the array
	 *Start at the end of array(size-1)&output.
	 **/
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/** Sort array using output **/
	for (i = 0; i  < (int)size; i++)
	{
		array[i] = output[i];
	}

	free(count);
	free(output);
}
