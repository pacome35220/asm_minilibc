/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memset
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
void	*(*my_memset)(char*, int, size_t);
char	*ret;
char	*sys;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_memset = dlsym(handle, "memset");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
}

Test(utils, nil_memset, .init = init, .fini = fini)
{
	char buff1[512];
	char buff2[512];

	ret = memset(buff1, '\0', sizeof(buff1));
	sys = memset(buff2, '\0', sizeof(buff2));
	cr_assert(ret == buff1 && sys == buff2);
	cr_assert(memcmp(buff1, buff2, sizeof(buff1)) == 0);
}

Test(utils, 1_memset, .init = init, .fini = fini)
{
	char buff1[512];
	char buff2[512];

	ret = memset(buff1, 'a', 1);
	sys = memset(buff2, 'a', 1);
	buff1[1] = '\0';
	buff2[1] = '\0';
	cr_assert(ret == buff1 && sys == buff2);
	cr_assert(strcmp(buff1, buff2) == 0);
}

Test(utils, buffer_long_letter, .init = init, .fini = fini)
{
	char buff1[512];
	char buff2[512];

	ret = memset(buff1, 'a', sizeof(buff1));
	sys = memset(buff2, 'a', sizeof(buff2));
	buff1[sizeof(buff1) - 1] = '\0';
	buff2[sizeof(buff2) - 1] = '\0';
	cr_assert(ret == buff1 && sys == buff2);
	cr_assert(strcmp(buff1, buff2) == 0);
}

Test(utils, struct_, .init = init, .fini = fini)
{
	struct data {
		int i;
		char *p;
		char b[7];
		short s;
	};
	struct data data1;
	struct data data2;

	struct data *ret = memset(&data1, 'a', sizeof(data1));
	struct data *sys = memset(&data2, 'a', sizeof(data2));

	cr_assert(ret == &data1 && sys == &data2);
	cr_assert(memcmp(&data1, &data2, sizeof(data2)) == 0);
}
