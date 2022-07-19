#include "deck.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * get_value - maps card values to integers
 * @value: card value
 * Return: returns the mapped integer value of the input
 */

int get_value(const char *value)
{
	int res;

	switch (value[0])
	{
	case 'A':
		return (1);
	case 'J':
		return (11);
	case 'Q':
		return (12);
	case 'K':
		return (13);
	default:
		res = atoi(value);
		return (res);
	}
}
/**
 * less - compares two deck_node_t nodes
 * @first: first node
 * @second: second node
 * Return: 1 if first < second else 0
 */

int less(deck_node_t *first, deck_node_t *second)
{
	int res;

	if (first->card->kind != second->card->kind)
		return (first->card->kind < second->card->kind);

	res = get_value(first->card->value) < get_value(second->card->value);
	return (res);
}

/**
 * swap - swaps two nodes in a deck_node_t list
 * @deck: Pointer to the head of the list
 * @first: First node
 * @second: Second node
 */
void swap(deck_node_t **deck, deck_node_t *first, deck_node_t *second)
{
	deck_node_t *fprev = first->prev, *snext = second->next;

	second->prev = fprev;
	fprev ? fprev->next = second : NULL;
	second->next = first;

	first->prev = second;
	first->next = snext;
	snext ? snext->prev = first : NULL;

	if (second->prev == NULL)
		*deck = second;
}

/**
 * sort_deck - sort a deck of card in a deck_node_t list
 * @deck: Pointer to the a deck_node_t list
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next;

	if (deck == NULL)
		return;
	current = *deck;
	while (current)
	{
		next = current->next;
		while (current->prev != NULL && less(current, current->prev))
			swap(deck, current->prev, current);
		current = next;
	}
}
