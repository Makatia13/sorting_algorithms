#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of ints
 *
 * @array: The array to be pri'ted
 * @size: Numb of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
