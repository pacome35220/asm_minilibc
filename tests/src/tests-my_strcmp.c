/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcmp
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

Test(utils, simple_strcmp)
{
	void	*handle;
	int	(*my_strcmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, good_strcmp)
{
	void	*handle;
	int	(*my_strcmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcmp)
{
	void	*handle;
	int	(*my_strcmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour2");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcmp2)
{
	void	*handle;
	int	(*my_strcmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}
