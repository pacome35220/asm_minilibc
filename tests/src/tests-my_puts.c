/*
** EPITECH PROJECT, 2018
** tests_my_puts
** File description:
** tests_my_puts
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <unistd.h>
#include <wait.h>

void	*handle;
int	(*my_puts)(const char *s);
int	ret_sys;
int	my_ret;
char	*s1;
char	*s2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_puts = dlsym(handle, "puts");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(s1);
	free(s2);
}

static char *get_stdout(int (*ptr)(const char *s), int *res, char *s)
{
	char buff[512] = { '\0' };
	int fd[2];
	pid_t pid;

	assert(pipe(fd) != -1);
	pid = fork();
	assert(pid != -1);
	if (pid == 0) {
		assert(dup2(fd[1], STDOUT_FILENO) != -1);
		exit((*ptr)(s));
	} else {
		assert(read(fd[0], buff, sizeof(buff)) != -1);
		assert(wait(res) != -1);
		if (WIFEXITED(*res))
			*res = WEXITSTATUS(*res);
	}
	return strdup(buff);
}

/*
Test(utils, hello_world, .init = init, .fini = fini)
{
	s1 = get_stdout(my_puts, &my_ret, "Hello World !");
	s2 = get_stdout(puts, &ret_sys, "Hello World !");
	fprintf(stderr, "s1: |%s|\n", s1);
	fprintf(stderr, "s2: |%s|\n", s2);
	cr_assert(ret_sys == my_ret);
	cr_assert(strcmp(s1, s2) == 0);
}

Test(utils, char_1, .init = init, .fini = fini)
{
	s1 = get_stdout(my_puts, &my_ret, "a");
	s2 = get_stdout(puts, &ret_sys, "a");
	fprintf(stderr, "s1: |%s|\n", s1);
	fprintf(stderr, "s2: |%s|\n", s2);
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}
*/

Test(utils, empty_string, .init = init, .fini = fini)
{
	s1 = get_stdout(my_puts, &my_ret, "");
	s2 = get_stdout(puts, &ret_sys, "");
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}

/*
Test(utils, null_ptr, .init = init, .fini = fini, .signal=SIGSEGV)
{
	s1 = get_stdout(my_puts, &my_ret, NULL);
	s2 = get_stdout(puts, &ret_sys, NULL);
	assert(ret_sys == my_ret);
	assert(strcmp(s1, s2) == 0);
}
*/
