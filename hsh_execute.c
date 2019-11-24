#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"
/**
 * hsh_execute - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int hsh_execute(char **args)
{
int i;
builtins bins[] = {
{"cd", hsh_cd},
{"help", hsh_help},
{"exit", hsh_exit},
{"env", hsh_env},
{"ls", hsh_ls},
{NULL, NULL}
};

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
