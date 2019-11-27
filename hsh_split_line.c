#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <string.h>
#include "holberton.h"

/**
  * hsh_split_line - Split a line into tokens.
  * @line: The line.
  * Return: Null-terminated array of tokens.
 */
char **hsh_split_line(char *line)
{
int hsh_tok_bufsize = 64;
char hsh_tok_delim = " \t\r\n\a";
int bufsize = hsh_tok_bufsize, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
write(STDERR_FILENO, "hsh: allocation error\n", 22);
free(tokens);
exit(EXIT_FAILURE);
}
token = strtok(line, hsh_tok_delim);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += hsh_tok_bufsize;
tokens = malloc(sizeof(tokens) + bufsize *sizeof(char *));
if (!tokens)
{
write(STDERR_FILENO, "hsh: allocation error\n", 22);
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, hsh_tok_bufsize);
}
tokens[position] = NULL;
return (tokens);
}
