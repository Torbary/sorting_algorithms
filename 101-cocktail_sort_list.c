#include "sort.h"

/**
 *  swap_nodes - swap two node
 *  @list : pointer to a pointer to the list
 *  @node1: pointer to the head of the first node
 *  @node2: pointer to the head of the second node
 *
 *  Return: 0
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{

	if (node1 == NULL || node2 == NULL)
	        return;

    	if (node1->prev != NULL)
        	node1->prev->next = node2;

    	if (node2->next != NULL)
        	node2->next->prev = node1;

	node1->next = node2->next;		
    	node2->prev = node1->prev;
    	node1->prev = node2;
    	node2->next = node1;

    	if (node1->prev == NULL)
       		 *list = node1;
}

/** cocktail_sort_list - Sorts a doubly linked list using the Cocktail shaker
 *  sort algorithm
 *  @list: pointer to a pointer to the head of a doubly linked list
 *
 *  Return: 0
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped = 0;

	if (list == NULL || (*list) == NULL || (*list)->next ==  NULL)
		return;

	start = *list;
	end = NULL;

	while (swapped || end == NULL)
	{
		swapped = 0;
		current = start;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
		{
			break;
		}

		swapped = 0;
		end = current;

		for (current = end->prev; current != start;
		       current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev,
					   current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current->next;
	}
}
