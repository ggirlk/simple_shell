/**
 * _strcmp - Compares pointers to two strings.
 * @s1: first string to be compared.
 * @s2: second string to be compared.
 * Return: negative, 0 or a positive number
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}
