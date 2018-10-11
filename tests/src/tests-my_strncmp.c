/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strncmp
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(utils, simple_strncmp)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp2)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 20) == (*my_strncmp)(str, str2, 20));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp3)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour2");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp4)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonjour");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strncmp)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("One more test!");
	char	*str2 = strdup("One more");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	printf("ret:%d\nsys_ret:%d\n", (*my_strncmp)(str, str2, 8), strncmp(str, str2, 8));
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strncmp2)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup("One More Test!");
	char	*str2 = strdup("One more");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
	cr_assert(strncmp(str, str2, 16) == (*my_strncmp)(str, str2, 16));
	dlclose(handle);
	free(str);
}

Test(utils, not_0_check)
{
	void	*handle;
	int	(*my_strncmp)(const char*, const char*, size_t);
	char	*error;
	char	*str = strdup(" ");
	char	*str2 = strdup("");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strncmp(str, str2, 0) == (*my_strncmp)(str, str2, 0));
	dlclose(handle);
	free(str);
}
