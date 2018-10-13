/*
** EPITECH PROJECT, 2018
** tests_my_putchar
** File description:
** tests_my_putchar
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <unistd.h>
#include <wait.h>

void	*handle;
int	(*my_putchar)(int c);
int	ret_sys;
int	my_ret;
char	*s1;
char	*s2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_putchar = dlsym(handle, "putchar");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(s1);
	free(s2);
}

char *get_stdout(int (*ptr)(int c), int *res, char c)
{
	char buff[8] = { '\0' };
	int fd[2];
	pid_t pid;

	assert(pipe(fd) != -1);
	pid = fork();
	assert(pid != -1);
	if (pid == 0) {
		dup2(fd[1], STDOUT_FILENO);
		exit((*ptr)(c));
	} else {
		assert(read(fd[0], buff, sizeof(buff)) != -1);
		assert(wait(res) != -1);
		if (WIFEXITED(*res))
			*res = WEXITSTATUS(*res);
	}
	return strdup(buff);
}

Test(utils, a, .init = init, .fini = fini)
{
	s1 = get_stdout(my_putchar, &my_ret, 'a');
	s2 = get_stdout(putchar, &ret_sys, 'a');
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}

Test(utils, back_n, .init = init, .fini = fini)
{
	s1 = get_stdout(my_putchar, &my_ret, '\n');
	s2 = get_stdout(putchar, &ret_sys, '\n');
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}

Test(utils, wtf, .init = init, .fini = fini)
{
	s1 = get_stdout(my_putchar, &my_ret, -42);
	s2 = get_stdout(putchar, &ret_sys, -42);
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}
