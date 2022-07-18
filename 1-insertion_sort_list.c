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
 * insertion_sort_list - sorts a listint_t list unsing insertion sort
 * algorithm
 * @list: Pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL)
		return;

	current = *list;
	while (current)
	{
		next = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap(list, current->prev, current);
			print_list(*list);
		}
		current = next;
	}
}
