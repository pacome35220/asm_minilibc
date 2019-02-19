/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strchr tests
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
char	*(*my_strchr)(char*, int);
char	*str;
char	*ret_sys;
char	*my_ret;

static void init(void)
{
        handle = dlopen("./libasm.so", RTLD_LAZY);
        assert(handle);
        my_strchr = dlsym(handle, "strchr");
        assert(!dlerror());
}

static void fini(void)
{
        dlclose(handle);
        free(str);
}

Test(utils, simple_strchr, .init = init, .fini = fini)
{
        str = strdup("bonjour");
        assert(str);
        ret_sys = strchr(str, 'j');
        my_ret = (*my_strchr)(str, 'j');
        cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strchr_not_found, .init = init, .fini = fini)
{
        str = strdup("bonjour");
        assert(str);
        my_ret = (*my_strchr)(str, 'z');
        cr_assert(my_ret == NULL);
}

Test(utils, strchr_empty_string, .init = init, .fini = fini)
{
        str = strdup("");
        assert(str);
        my_ret = (*my_strchr)(str, 'z');
        cr_assert(my_ret == NULL);
}

Test(utils, strchr_zero_empty_string, .init = init, .fini = fini)
{
        str = strdup("");
        assert(str);
        my_ret = (*my_strchr)(str, '\0');
        ret_sys = strchr(str, '\0');
        cr_assert(my_ret == ret_sys);
}

Test(utils, strchr_one_char, .init = init, .fini = fini)
{
        str = strdup("z");
        assert(str);
        my_ret = (*my_strchr)(str, 'z');
        ret_sys = strchr(str, 'z');
        cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strchr_zero, .init = init, .fini = fini)
{
        ret_sys = strchr("bonjour", 0);
        my_ret = (*my_strchr)("bonjour", 0);
        cr_assert(strcmp(ret_sys, my_ret) == 0);
}
