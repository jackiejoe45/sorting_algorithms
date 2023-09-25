#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to be sorted
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				tmp = current->next;
				current->next = tmp->next;
				tmp->next = current;
				tmp->prev = current->prev;
				current->prev = tmp;
				if (tmp->prev != NULL)
					tmp->prev->next = tmp;
				if (current->next != NULL)
					current->next->prev = current;
				swapped = 1;
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				tmp = current->prev;
				current->prev = tmp->prev;
				tmp->prev = current;
				tmp->next = current->next;
				current->next = tmp;
				if (tmp->next != NULL)
					tmp->next->prev = tmp;
				if (current->prev != NULL)
					current->prev->next = current;
				swapped = 1;
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
