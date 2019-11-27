# Simple Shell

Simple shell is a project of end semester, it helps to explore and manipulate and create basic shell program.

## Installation

You can install simple shell by cloning this repository:
```
https://github.com/ggirlk/simple_shell
```

## Compilation

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Testing
Interactive mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
Non-interactive mode
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```


