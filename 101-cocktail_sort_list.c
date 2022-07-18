#include "sort.h"

/**
 * swap - swaps two nodes in a listint_t list
 * @list: Pointer to the head of the list
 * @first: First node
 * @second: Second node
 */

void swap(listint_t **list, listint_t *first, listint_t *second)
{
	listint_t *fprev = first->prev, *snext = second->next;

	second->prev = fprev;
	fprev ? fprev->next = second : NULL;
	second->next = first;

	first->prev = second;
	first->next = snext;
	snext ? snext->prev = first : NULL;

	if (second->prev == NULL)
		*list = second;
}

/**
 * cocktail_sort_list - sorts an list using the coctail sort algorithm
 * @list: Pointer to the head of a linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;

	if (list == NULL || *list == NULL)
		return;
	start = current = *list;
	while (current->next)
		current = current->next;
	end = current;
	while (start != end && start != end->next)
	{
		current = start;
		while (current != end)
		{
			if (current->n > current->next->n)
			{
				if (current == start)
					start = current->next;
				if (current->next == end)
					end = current;
				swap(list, current, current->next);
				print_list(*list);
				continue;
			} current = current->next;
		} current = end = current->prev;
		while (current != start)
		{
			if (current->n < current->prev->n)
			{
				if (current == end)
					end = current->prev;
				if (current->prev == start)
					start = current;
				swap(list, current->prev, current);
				print_list(*list);
				continue;
			} current = current->prev;
		} start = current->next;
	}
}
