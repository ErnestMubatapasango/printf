#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * int_to_binary - Prints all of the arguments when specified
 * @num: specifies the necessary operations
 * Return: void
 */
char *int_to_binary(unsigned int num)
{
	int bit_count = sizeof(unsigned int) * 8;
	int i;
	char *binary_str = malloc(bit_count + 1);

	if (binary_str == NULL)
	{
	fprintf(stderr, "Error: Failed to allocate memory\n");
		exit(1);
	}
	binary_str[bit_count] = '\0';
	for (i = bit_count - 1; i >= 0; i--)
	{
		binary_str[i] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	return (binary_str);
}
/**
 * main - Program entry
 * Return: void
 */
int main(void)
{
	unsigned int num = 42;
	char *binary_str = int_to_binary(num);

	printf("Decimal: %u\nBinary: %s\n", num, binary_str);
	free(binary_str);
	return (0);
}
