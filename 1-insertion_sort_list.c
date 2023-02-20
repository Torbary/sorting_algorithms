#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list in an ascending order
 * @list:  Double pointer to the first node in the list
 *
 * Return: 0
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *prev_node, *temp_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		prev_node = current_node->prev;

		while (prev_node != NULL && prev_node->n > current_node->n)
		{
			temp_node = prev_node->prev;
			prev_node->next = current_node->next;
			current_node->prev = prev_node->prev;
			prev_node->prev = current_node;
			current_node->next = prev_node;

			if (prev_node->next != NULL)
				prev_node->next->prev = prev_node;
			if (current_node->prev != NULL)
				prev_node->prev->next = current_node;
			else
				*list = current_node;
			 prev_node->prev = current_node;
			 current_node->next = prev_node;

			print_list(*list);

			prev_node = temp_node;
		}
		current_node = current_node->next;
	}
}
