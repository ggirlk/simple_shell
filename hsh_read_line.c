#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * hsh_read_line - Read a line of input from stdin.
 * Return: line from stdin.
 */
char *hsh_read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
int n = 0, k;
char *eof = "\n";
k = isatty(STDIN_FILENO);
n = getline(&line, &bufsize, stdin);
if (n == -1)
{
if (k == 1)
write(1, eof, _strlen(eof));
exit(0);
}
return (line);
}
