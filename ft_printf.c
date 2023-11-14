#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int p;
	p = 0;
	while(*format)
	{
		if(*format != '%')
		{
		ft_putchar_fd(*format, 1);
		format++;
		p++;
		}
	}
	va_end(args);
	return(p);
}


int main() {
    char ch = 'A';
    char *str = "Hello, World!";
    int decimalNum = 42;
    unsigned int unsignedNum = 100;
    int hexNum = 0xABCD;

    printf("%%c: %c\n", ch);
    printf("%%s: %s\n", str);
    printf("%%p: %p\n", (void *)&hexNum);
    printf("%%d: %d\n", decimalNum);
    printf("%%i: %i\n", decimalNum);
    printf("%%u: %u\n", unsignedNum);
    printf("%%x: %x\n", hexNum);
    printf("%%X: %X\n", hexNum);
    printf("%%%%: %%\n");

	int p = ft_printf("Hello printf");
	printf("%d", p);


    return 0;
}