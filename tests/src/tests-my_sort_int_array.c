/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** my_sort_int_array test
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

void	*handle;
void	(*my_sort_int_array)(int *array, int size);

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_sort_int_array = dlsym(handle, "my_sort_int_array");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
}

static bool is_sort(int *array, int size)
{
	if (!size || !array)
		return true;
	for (int i = 0; i < size - 1; i++)
		if (array[i + 1] < array[i])
			return false;
	return true;
}

static bool array_cmp(int *array1, int *array2, int size)
{
	if (!array1 || !array2 || !size)
		return true;
	for (int i = 0; i < size - 1; i++)
		if (array1[i] != array2[i])
			return false;
	return true;
}

Test(utils, empty_array, .init = init, .fini = fini)
{
	int tab[] = {};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(array_cmp(tab, tab, ARRAY_SIZE(tab)));
	assert(!memcmp(tab, tab, ARRAY_SIZE(tab)));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, basic, .init = init, .fini = fini)
{
	int tab[] = {4, 6, 1, 3, 8};
	int tab1[] = {1, 3, 4, 6, 8};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(array_cmp(tab, tab1, ARRAY_SIZE(tab)));
	assert(!memcmp(tab, tab1, ARRAY_SIZE(tab)));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, big, .init = init, .fini = fini)
{
	int tab[] = {-234, 4545, 66767, 4, 6, 10, 3, 8, 23245, 14324, 765, -2344, 0};
	int tab1[] = {-2344, -234, 0, 3, 4, 6, 8, 10, 765, 4545, 14324, 23245, 66767};

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(array_cmp(tab, tab1, ARRAY_SIZE(tab)));
	assert(!memcmp(tab, tab1, ARRAY_SIZE(tab)));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, one_element, .init = init, .fini = fini)
{
	int tab[] = { 4 };

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(array_cmp(tab, tab, ARRAY_SIZE(tab)));
	assert(!memcmp(tab, tab, ARRAY_SIZE(tab)));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}

Test(utils, 2_same_element, .init = init, .fini = fini)
{
	int tab[] = { 4, 4 };

	my_sort_int_array(tab, ARRAY_SIZE(tab));
	assert(array_cmp(tab, tab, ARRAY_SIZE(tab)));
	assert(!memcmp(tab, tab, ARRAY_SIZE(tab)));
	assert(is_sort(tab, ARRAY_SIZE(tab)));
}
