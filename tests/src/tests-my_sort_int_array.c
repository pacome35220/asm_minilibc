/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** my_sort_int_array test
*/

#include <assert.h>
#include <criterion/criterion.h>

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

void	my_sort_int_array(int *array, int size);

static bool is_sort(int *array, int size)
{
	if (!size || !array)
		return true;
	for (int i = 0; i < size - 1; i++)
		if (array[i + 1] < array[i])
			return false;
	return true;
}

Test(utils, empty_array)
{
	int tab[] = {};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, basic)
{
	int tab[] = {4, 6, 1, 3, 8};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, big)
{
	int tab[] = {-234, 4545, 66767, 4, 6, 10, 3, 8, 23245, 14324, 765, -2344, 0};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, one_element)
{
	int tab[] = { 4 };

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}
