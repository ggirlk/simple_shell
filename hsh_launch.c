#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"
/**
 * hsh_launch - launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments.
 * Return: Always returns 1, to continue execution.
 */
int hsh_launch(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
/* Child process */
if (execve(args[0], args, NULL) == -1)
{
perror("hsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror("hsh");
}
else {
/* Parent process */
do
{
waitpid(pid, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}
