#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
  * hsh_loop - gets input and executs it.
  * Return: Nothing
 */
void hsh_loop(char *progname)
{
char *line;
char **args;
int status;

do
{
write(STDOUT_FILENO, "#cinsfun$ ", 10);
line = hsh_read_line();
args = hsh_split_line(line);
status = hsh_execute(args, progname);
free(line);
free(args);
}
while (status);
}
