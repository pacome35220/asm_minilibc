/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strpbrk tests
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(utils, simple_strpbrk)
{
	void	*handle;
	char	*(*my_strpbrk)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	ret_sys = strpbrk(str, "jour");
	my_ret = (*my_strpbrk)(str2, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_not_found)
{
	void	*handle;
	char	*(*my_strpbrk)(const char*,const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");
	char	*my_ret;
	char	*sys;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	sys = strpbrk(str2, "iteb");
	my_ret = (*my_strpbrk)(str, "iteb");
	cr_assert(strcmp(sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_empty_string)
{
	void	*handle;
	char	*(*my_strpbrk)(const char*, const char*);
	char	*error;
	char	*str = strdup("");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strpbrk)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_one_char)
{
	void	*handle;
	char	*(*my_strpbrk)(const char*, const char*);
	char	*error;
	char	*str = strdup("z");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strpbrk)(str, "z");
	char	*test;
	test = strpbrk(str, "z");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}
