#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int main()
{
	int i = 10;
	char *res = malloc(i);
	while (i--)
		res[i] = 'a';
	printf("%s",res);
}
