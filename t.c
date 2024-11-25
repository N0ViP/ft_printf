#include <stdio.h>


int main()
{
	char hex[16];

    int i;

    i = 0;
    while (i < 16)
	{
        hex[i] = "0123456789abcdef"[i];
		i++;
	}
	printf("%s", hex);
}
