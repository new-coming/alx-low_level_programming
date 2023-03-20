#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 *
 * Return: the first index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	int step = sqrt(size);
	int prev = 0;

	while (array[step - 1] < value && step < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (prev >= (int)size)
			return (-1);
	}

	while (array[prev] < value)
	{
		prev++;
		if (prev == step)
			return (-1);
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	}

	if (array[prev] == value)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		return (prev);
	}

	return (-1);
}
