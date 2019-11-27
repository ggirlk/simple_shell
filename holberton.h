#ifndef HOLBERTON_H
#define HOLBERTON_H

/**
 * struct builtins - structure of builtins and their related functions
 *
 * @builtin_str: The builtin command
 * @builtin_func: The function associated
 */
typedef struct builtins
{
char *builtin_str;
int (*builtin_func)(char **, char *);
} builtins;

int hsh_execute(char **args, char *);
int hsh_launch(char **args, char *);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
void hsh_loop(char *);
int hsh_num_builtins();
int hsh_cd(char **args, char *);
int hsh_help(char **args, char *);
int hsh_exit(char **args, char *);
int hsh_env(char **args, char *);
int hsh_ls(char **args, char *);
#endif /* HOLBERTON_H */
