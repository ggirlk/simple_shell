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
int main()
{
/* Run command loop. */
hsh_loop();

return (EXIT_SUCCESS);
}
