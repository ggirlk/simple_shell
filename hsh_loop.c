#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * hsh_loop - gets input and executs it.
 * @progname: the name of the executable program
 * ac: size of main program argv
 * Return: Nothing
 */
void hsh_loop(char *progname)
{
char *line;
char **args;
int status;
int n;
do {
n = isatty(STDIN_FILENO);
if (n == 1)
write(1, "$ ", 2);
line = hsh_read_line();
args = hsh_split_line(line);
status = hsh_execute(args, progname);
free(line);
free(args);
} while (status);
}
