#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration representing card suits.
 * @SPADE: Reps the Spades suit.
 * @HEART: Reps the Hearts suit.
 * @CLUB: Reps the Clubs suit.
 * @DIAMOND: Represents the Diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Reps a playing card.
 * @value: The value of the card, ranging from "Ace" to "King".
 * @kind: The suit or kind of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Reps a node in a deck of cards.
 * @card: Pointer to the card associated with the node.
 * @prev: Pointer to the previous node in the list.
 * @next: Pointer to the next node in the list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
