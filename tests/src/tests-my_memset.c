/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memset
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(utils, short_memset)
{
	void	*handle;
	void	*(*my_memset)(char*, int, size_t);
	char	*error;
	char	*str = strdup("bonjour");

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memset = dlsym(handle, "memset");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	str = (*my_memset)(str, 'a', strlen(str));
	cr_assert(strcmp(str, "aaaaaaa") == 0);
	dlclose(handle);
	free(str);
}


Test(utils, long_memset)
{
	void	*handle;
	void	*(*my_memset)(char*, int, size_t);
	char	*error;
	char	*str = strdup("bonjourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memset = dlsym(handle, "memset");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	str = (*my_memset)(str, 'a', strlen(str));
	cr_assert(strcmp(str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == 0);
	dlclose(handle);
	free(str);
}
