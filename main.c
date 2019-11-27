#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * main - main program: entry point.
 *
 * Return: status code
 */
int main(int ac __attribute__((unused)), char **av)
{
/* Run command loop. */
hsh_loop(av[0]);

return (EXIT_SUCCESS);
}
