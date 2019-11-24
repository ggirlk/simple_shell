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
int (*builtin_func)(char **);
} builtins;

int hsh_execute(char **args);
int hsh_launch(char **args);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
void hsh_loop(void);
int hsh_num_builtins();
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

#endif /* HOLBERTON_H */
