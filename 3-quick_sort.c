#include "sort.h"

/**
 * _swap - swap two numbers.
 * @a: integer
 * @b: integer
 **/

void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

/**
 * _part - Split the array and takes the last element as pivot
 * @array: Array
 * @min: first element
 * @last: The last element
 * @size: size
 * Return: int value
 **/
int _part(int *array, int min, int last, size_t size)
{
	int piv;
	int i = (min);
	int j;

	piv = array[last];
	for (j = min; j < last; j++)
	{
		if (array[j] <= piv)
		{
			_swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	_swap(&array[i], &array[last]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
 * q_sort - quick_sort_array
 * @array: array
 * @min: min
 * @last: last
 * @size: size
 * Return: void
 */
void q_sort(int *array, int min, int last, size_t size)
{

	int i;

	if (min < last)
	{
		i = _part(array, min, last, size);
		q_sort(array, min, (i - 1), size);
		q_sort(array, (i + 1), last, size);
	}
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * from min to max
 * @array: array
 * @size: size
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
