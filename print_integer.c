#include "main.h"
/**
 * print_integer - handle conversion specifiers
 * @num: number.
 * Return: Result.
 */
void print_integer(int num)
{
int divisor = 1;
if (num == 0)
{
putchar('0');
return;
}
if (num < 0)
{
putchar('-');
num = -num;
}

while (num / divisor > 9)
{
divisor *= 10;
}

while (divisor > 0)
{
int digit = num / divisor;
putchar(digit + '0');
num %= divisor;
divisor /= 10;
}
}

/**
 * main - Program entry
 * @void: no return type
 * Return: Success.
 */

int main(void)
{
int num = 12345;
printf("d: %d\n", num);
printf("i: %i\n", num);
print_integer(num);
return (0);
}

