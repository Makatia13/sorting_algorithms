#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of ints
 *
 * @list: The list to be pri'ed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
