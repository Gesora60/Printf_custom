#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == 'i' || 'd')
			{
				int num = va_arg(args, int);
				int digits = 0;
				int temp = num;
				int digit;
				if (num < 0)
				{
					count += putchar('-');
					num = -num;
					temp = num;
				}
				do {
					digits++;
					temp /= 10;
				} while (temp != 0);
				while (digits > 0)
				{
					int pow10 = 1;
					int i;
					for (i = 1; i < digits; i++)
					{
						pow10 *= 10;
					}
					digit = num / pow10;
					count += putchar(digit + '0');
					num -= digit * pow10;
					digits--;
				}
			}
			
			
		}
		format++;
	}
	va_end(args);
	return (count);
}

int main() {
    char *message = "Hello, World!";
    int number = 422;
    char character = 'A';

    int charsPrinted = _printf("This is a test:\n");
    charsPrinted += _printf("String: %s\n", message);
    charsPrinted += _printf("Number: %d\n", number);
    charsPrinted += _printf("Character: %c\n", character);
    charsPrinted += _printf("Percent sign: %%\n");
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Total characters printed: %d\n", charsPrinted);

    return 0;
}














