#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order.
 * @list: Head of the list.
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
/* Used to traverse the list during sorting. */
listint_t *temp;

        /* Check if the list is empty or has only one element. */
        if (*list == NULL || (*list)->next == NULL)
                return;

        /* Assign temp to the second node, as the first is already sorted. */
        temp = (*list)->next;
        while (temp)
        {
                while ((temp->prev) && (temp->prev->n > temp->n))
                {
                        temp = swap_node(temp, list);  /* Swap nodes and update temp. */
                        print_list(*list);  /* Print the list after each swap. */
                }
                temp = temp->next;
        }
}

/**
 * swap_node - Swaps the values in the list.
 * @temp: Points to the second node.
 * @list: Points to the head of the list.
 * Return: Current node.
 */
listint_t *swap_node(listint_t *temp, listint_t **list)
{
        /* 'behind' represents the node before 'current', and 'current' is the node to be swapped. */
        listint_t *current = temp, *behind = temp->prev;

        /* Update the 'next' pointer of the node before 'current' to point to the node after 'current'. */
        behind->next = current->next;

        if (current->next)
                current->next->prev = behind;  /* Update the 'prev' pointer of the node after 'current'. */

        /* Update the 'next' pointer of 'current' to point to 'behind'. */
        current->next = behind;

        /* Update the 'prev' pointer of 'current' to point to the node before 'behind'. */
        current->prev = behind->prev;

        /* Update the 'prev' pointer of 'behind' to point to 'current'. */
        behind->prev = current;

        if (current->prev)
                current->prev->next = current;  /* Update the 'next' pointer of the node before 'current'. */
        else
                *list = current;/* Update the head of the list*/

        return (current);  /* Return the current node. */
}
