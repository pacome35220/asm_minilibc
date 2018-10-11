/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strcasecmp test
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(utils, simple_strcasecmp)
{
	void	*handle;
	int	(*my_strcasecmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, good_strcasecmp)
{
	void	*handle;
	int	(*my_strcasecmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("boNJOur");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcasecmp)
{
	void	*handle;
	int	(*my_strcasecmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonJouR");
	char	*str2 = strdup("bonjour2");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcasecmp2)
{
	void	*handle;
	int	(*my_strcasecmp)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonJouR");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}
