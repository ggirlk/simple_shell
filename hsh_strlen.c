#include <stdio.h>
/**
 * _strlen - Function that give us length
 * @s: String
 * Return: len
 */
int _strlen(char *s)
{
int len = 0;
while (*s != 0)
{
s++;
len++;
}
return (len);
}
