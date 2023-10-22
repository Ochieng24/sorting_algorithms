#include "sort.h"
/**
  * insertion_sort_list - sorts a doubly linked list of int in ascending order
  * @list: head of the list
  * Return: void
  */

void insertion_sort_list(listint_t **list)
{
	/*used to traverse the list during sorting*/
	listint_t *temp;

	/* checks if the list is empty or has only one element */
	if (*list == NULL || (*list)->next == NULL)
		return;

	/* assign temp to second node. the first is already sorted */
	temp = (*list)->next;
	while (temp)
	{
		while ((temp->prev) && (temp->prev->n > temp->n))
		{
			temp = swap_node(temp, list);
			print_list(*list);
		}
		temp = temp->next;
	}
}

/**
  * swap_node - swaps the value in the list
  * @temp: point to second node
  * @list: point to head of the list
  * Return: current node
  */
listint_t *swap_node(listint_t *temp, listint_t **list)
{
	/* behind is node before current, current is node to be swapped*/
	listint_t *current = temp, *behind = temp->prev;

	behind->next = current->next;
	if (current->next)
		current->next->prev = behind;
	current->next = behind;
	current->prev = behind->prev;
	behind->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
