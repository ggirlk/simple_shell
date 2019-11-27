#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <string.h>
#include "holberton.h"

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"
/**
  * hsh_split_line - Split a line into tokens.
  * @line: The line.
  * Return: Null-terminated array of tokens.
 */
char **hsh_split_line(char *line)
{
int bufsize = HSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize *sizeof(char *));
char *token;
if (!tokens)
{
write(STDERR_FILENO, "hsh: allocation error\n", 22);
exit(EXIT_FAILURE);
}
token = strtok(line, HSH_TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += HSH_TOK_BUFSIZE;
tokens = malloc(sizeof(tokens) + bufsize * sizeof(char *));
if (!tokens)
{
write(STDERR_FILENO, "hsh: allocation error\n", 22);
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, HSH_TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
