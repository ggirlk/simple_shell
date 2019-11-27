#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

#define HSH_RL_BUFSIZE 1024
/**
 * hsh_read_line: Read a line of input from stdin.
 * Return: line from stdin.
 */
char *hsh_read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
int n = 0;
char *eof = "^D\n";
n = getline(&line, &bufsize, stdin);
if (n == -1)
{
write(STDOUT_FILENO, eof, _strlen(eof));
exit(0);
}
return (line);
}
