#include "main.h"

void print_hedge(char hedge[], int *hed_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, hed_ind = 0;
	va_list list;
	char hedge[HED_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			hedge[hed_ind++] = format[i];
			if (hed_ind == HED_SIZE)
				print_hedge(hedge, &hed_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_hedge(hedge, &hed_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, hedge,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_hedge(hedge, &hed_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_hedge - Prints the contents of the buffer if it exist
 * @hedge: Array of chars
 * @hed_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char hedge[], int *hed_ind)
{
	if (*hed_ind > 0)
		write(1, &hedge[0], *hed_ind);

	*hed_ind = 0;
}

