#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "holberton.h"

/**
 * hsh_help - builtin command: print help.
 * @args List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int hsh_help(char **args __attribute__((unused)), char *progname __attribute__((unused)))
{
int i;
char *msg[] = {
"Holberton Student HSH\nThe following are built in:\n",
"You can use man for more infos.\n"
};
builtins bins[] = {
{"cd", hsh_cd},
{"help", hsh_help},
{"exit", hsh_exit},
{"env", hsh_env},
{"ls", hsh_ls},
{NULL, NULL}
};

write(STDOUT_FILENO, msg[0], _strlen(msg[0]));

for (i = 0; i < hsh_num_builtins(); i++)
{
write(STDOUT_FILENO, bins[i].builtin_str, _strlen(bins[i].builtin_str));
write(STDOUT_FILENO, "\n", 1);
}
write(STDOUT_FILENO, msg[1], _strlen(msg[1]));
return (1);
}
