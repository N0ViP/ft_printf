#include "ft_printf.h"

int main()
{
	ft_printf("hello %i\ngood %u\nhhhhh %p\ngg %x\n raatt %X\n fin %%\n", -2147483648, -1, (void *) "good", 1337);
}
