#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in asce order
 * @list: Double pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
if (*list == NULL || (*list)->next == NULL)
return; /* If the list is empty or has only one element, it's already sorted.*/

listint_t *current = (*list)->next; /*Initialize the 'current' pointer*/

while (current != NULL)
{
listint_t *temp = current; /*'temp' points tcurren node*/

while (temp->prev != NULL && temp->n < temp->prev->n)
{
swap_nodes(temp, list); /*Swap the nodes*/
print_list(*list); /* Print the list after swapping.*/
}

current = current->next; /*Move to the next node to continue sorting.*/
}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node: The node to be swapped
 * @list: Double pointer to the head of the list
 */
void swap_nodes(listint_t *node, listint_t **list)
{
listint_t *prev_node = node->prev; /*'prev_node' points to prev node.*/

if (prev_node)
prev_node->next = node->next; /*Adjust the 'next' pointer*/

if (node->next)
node->next->prev = prev_node; /*Adjust the 'prev' pointer*/

node->prev = prev_node->prev; /* Update the next pointer*/
node->next = prev_node; /* Set the 'next' pointer*/

if (prev_node->prev)
prev_node->prev->next = node; /*Update the 'next' ptr*/
else
*list = node; /*Update the head of the list if needed.*/

prev_node->prev = node; /*Update the 'prev' ptr */
}
