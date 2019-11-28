#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"
#include <signal.h>
/**
 * hsh_sigintHandler - Reset handler to catch SIGINT next time.
 * @sig_num: int signal number
 * Return: nothing
 */
void hsh_sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, hsh_sigintHandler);
write(1, "\n$ ", 3);
}
/**
 * main - main program: entry point.
 * @ac: size of av
 * @av: a NULL determinated list of arguments
 * Return: status code
 */
int main(int ac __attribute__((unused)), char **av)
{
/* ignore Ctrl + c event */
signal(SIGINT, hsh_sigintHandler);

/* Run command loop. */
hsh_loop(av[0]);

return (EXIT_SUCCESS);
}
