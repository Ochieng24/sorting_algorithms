#include "sort.h"
/**
 *knuth - helper func that generates the knuth sequence used in the sort
 *@size: size to generate the sequence upto
 *@sequence: pointer to an array where the generated sequence is stored
 */
void knuth(int *sequence, int size)
{
        int n, i;

        n = 1;
        i = 0;

        while (n < size)
        {
                sequence[i++] = n;
                n = n * 3 + 1;
        }
}

/**
 *shell_sort -  sorts an array of integers in ascending order using
 *the Shell sort algorithm, using the Knuth sequence
 *@array: list to sort
 *@size: of the array
 */
void shell_sort(int *array, size_t size)
{
        int *knuth_sequence = malloc(size * sizeof(size_t));
        int k, interval;
        size_t i;

        knuth(knuth_sequence, size);

        for (k = size - 1; k >= 0; k--)
        {
                interval = knuth_sequence[k];

                for (i = interval; i < size; i++)
                {
                        int temp = array[i];
                        int j = i;

                        while (j >= interval && array[j - interval] > temp)
                        {
                                array[j] = array[j - interval];
                                j -= interval;
                        }
                        array[j] = temp;
                }
        }
        print_array(array, size);
}
