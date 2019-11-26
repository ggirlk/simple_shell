#include <stdio.h>
/*
* _strlen: Function that give us the length
* len: Length
* return: len
*/
int _strlen(char *s)
{
int len = 0;
while(*s != 0) {
s++;
len++;
}
return len;
}
