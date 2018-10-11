/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcspn
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(strcspn, simple_strcspn)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("bonjour");
	char    *str2 = strdup("o");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, simple_strcspn2)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("bonjour");
	char    *str2 = strdup("or");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, simple_strcspn3)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("bonjour");
	char    *str2 = strdup("slt");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, first_empty)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("");
	char    *str2 = strdup("abcd");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, second_empty)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("bonjour");
	char    *str2 = strdup("");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, both_empty)
{
	void    *handle;
	int    (*my_strcspn)(const char*, const char*);
	char    *error;
	char    *str = strdup("");
	char    *str2 = strdup("");
	int    ret_sys;
	int    my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);		        
	}
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}
