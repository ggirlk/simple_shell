#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * main - main program: entry point.
 * @ac: size of av
 * @av: a NULL determinated list of arguments
 * Return: status code
 */
int main(int ac __attribute__((unused)), char **av)
{
/* Run command loop. */
hsh_loop(av[0]);

return (EXIT_SUCCESS);
}
