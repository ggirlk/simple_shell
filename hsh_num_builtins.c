#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * hsh_num_builtins - counts the number of builtins
 * Return: the number of builtins
 */
int hsh_num_builtins(void)
{
builtins bins[] = {
{"cd", hsh_cd},
{"help", hsh_help},
{"exit", hsh_exit},
{"env", hsh_env},
{"ls", hsh_ls},
{NULL, NULL}
};
int i = 0;
while (bins[i].builtin_str)
i++;
return (i);
}
