#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

const builtins bins[] = {
{"cd", hsh_cd},
{"help", hsh_help},
{"exit", hsh_exit},
{NULL, NULL}
};

int hsh_num_builtins(void)
{
int i = 0;
while (bins[i].builtin_str)
i++;
return (i);
}

/**
 * hsh_cd - builtin command: change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: Always returns 1, to continue executing.
 */
int hsh_cd(char **args)
{
if (args[1] == NULL)
{
write(STDOUT_FILENO, "hsh: expected argument to \"cd\"\n", 34);
}
else
{
if (chdir(args[1]) != 0)
{
perror("lsh");
}
}
return (1);
}

/**
 * hsh_help - builtin command: print help.
 * @args List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int hsh_help(char **args __attribute__((unused)))
{
int i;
char *msg[] = {
"Holberton Student HSH\nThe following are built in:\n",
"You can use man for more infos.\n"
};

write(STDOUT_FILENO, msg[0], strlen(msg[0]));

for (i = 0; i < hsh_num_builtins(); i++)
{
write(STDOUT_FILENO, bins[i].builtin_str, strlen(bins[i].builtin_str));
write(STDOUT_FILENO, "\n", 1);
}
write(STDOUT_FILENO, msg[1], strlen(msg[1]));
return (1);
}

/**
 * hsh_execute - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int hsh_execute(char **args)
{
int i;
if (args[0] == NULL)
{
/* An empty command was entered */
return (1);
}

for (i = 0; i < hsh_num_builtins(); i++)
{
if (strcmp(args[0], bins[i].builtin_str) == 0)
{
return ((*bins[i].builtin_func)(args));
}
}

return (hsh_launch(args));
}

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
char **tokens = malloc(bufsize *sizeof(char*));
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
tokens = malloc(sizeof(tokens) + bufsize * sizeof(char*));
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

/**
  * hsh_loop - gets input and executs it.
  * Return: Nothing
 */
void hsh_loop(void)
{
char *line;
char **args;
int status;

do
{
write(STDOUT_FILENO, "#cinsfun$ ", 10);
line = hsh_read_line();
args = hsh_split_line(line);
status = hsh_execute(args);
free(line);
free(args);
}
while (status);
}

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
