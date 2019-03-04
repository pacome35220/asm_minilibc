/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memcpy
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
void	*(*my_memcpy)(void*, const void *, size_t);
char	*str;
char	*ret;
char	*sys;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_memcpy = dlsym(handle, "memcpy");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
}

Test(utils, simple_memcpy, .init = init, .fini = fini)
{
	char buff1[32] = "";
	char buff2[32] = "";

	str = strdup("zfdergfcvtrryhtyt");
	assert(str);

	ret = (*my_memcpy)(buff1, str, strlen(str));
	sys = memcpy(buff2, str, strlen(str));
	cr_assert(strcmp(buff1, buff2) == 0);
	cr_assert(ret == buff1 && sys == buff2);
}

Test(utils, empty, .init = init, .fini = fini)
{
	char buff1[32] = "";
	char buff2[32] = "";

	str = strdup("");
	assert(str);

	ret = (*my_memcpy)(buff1, str, strlen(str));
	sys = memcpy(buff2, str, strlen(str));
	cr_assert(ret == buff1 && sys == buff2);
	cr_assert(strcmp(buff1, buff2) == 0);
}

Test(utils, one_char, .init = init, .fini = fini)
{
	char buff1[32] = "";
	char buff2[32] = "";

	str = strdup("a");
	assert(str);

	ret = (*my_memcpy)(buff1, str, strlen(str));
	sys = memcpy(buff2, str, strlen(str));
	cr_assert(ret == buff1 && sys == buff2);
	cr_assert(strcmp(buff1, buff2) == 0);
}

Test(utils, copy_struct_, .init = init, .fini = fini)
{
	struct data {
		int i;
		char *p;
		short s;
	};
	struct data dest;
	struct data src = { .i = 4, .p = "mdr", .s = 42 };

	struct data *ret = memset(&dest, '\0', sizeof(struct data));
	struct data *sys = memset(&src, '\0', sizeof(struct data));

	ret = (*my_memcpy)(&dest, &src, sizeof(struct data));
	sys = memcpy(&dest, &src, sizeof(struct data));

	cr_assert(ret == sys);
	cr_assert(memcmp(&dest, &src, sizeof(struct data)) == 0);
}
