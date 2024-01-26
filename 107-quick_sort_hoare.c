#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The 1st integer to swap.
 * @b: The 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of ints
 *                   according to the hoare partition scheme.
 * @array: The array of ints.
 * @size: The size of the array.
 * @left: The starting indx of the subset to order.
 * @right: The ending indx of the subset to order.
 *
 * Return: The final par'tion index.
 *
 * Description: Uses the last element of the par'tion as the pivot.
 * Prints the array after each swap of two ele'nts.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algo through recursion.
 * @array: An array of ints to sort.
 * @size: The size of the array.
 * @left: The starting index of the array par'tion to order.
 * @right: The ending index of the array par'tion to order.
 *
 * Description: Uses the Hoare par'tion scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of ints in ascending
 *                    order using the quicksort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array aftr each swap of two ele'nts.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
