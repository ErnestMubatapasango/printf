#include "main.h"
/**
 * handle_conversion - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int handle_conversion(const char *format, ...)
{
va_list args;
int count = 0;
int divisor;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
putchar(c);
count++;
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
if (num < 0)
{
putchar('-');
count++;
num = -num;
}
divisor = 1;
while (num / divisor > 9)
{
divisor *= 10;
}
while (divisor > 0)
{
int digit = num / divisor;
putchar(digit + '0');
count++;
num %= divisor;
divisor /= 10;
}
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}

