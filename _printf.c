#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, display = 0, display_chars = 0;
	int emblem, width, accurate, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
						display_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			emblem = get_emblem(format, &i);
			width = get_width(format, &i, list);
			accurate = get_accurate(format, &i, list);
			size = get_size(format, &i);
			++i;
			display = handle_print(format, &i, list, buffer,
				emblem, width, accurate, size);
			if (display == -1)
				return (-1);
			display_chars += display;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (display_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
