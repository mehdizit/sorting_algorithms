#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	int m;
	listint_t *cur;

	cur = *list;
	if (cur->next == NULL)
		return;
	listint_t *ptr, *tmp;

	cur = cur->next;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (cur != NULL)
	{
		m = 0;
		ptr = cur;
		tmp = cur->prev;
		cur = cur->next;
		while (tmp != NULL && tmp->n > ptr->n)
		{
			m++;
			tmp = tmp->prev;
		}
		if (m)
		{
			ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			if (tmp == NULL)
			{
				tmp = *list;
				ptr->prev = NULL;
				ptr->next = tmp;
				ptr->next->prev = ptr;
				*list = ptr;
			}
			else
			{
				tmp = tmp->next;
				tmp->prev->next = ptr;
				ptr->prev = tmp->prev;
				tmp->prev = ptr;
				ptr->next = tmp;
			}
		}
		print_list(*list);
	}
}
