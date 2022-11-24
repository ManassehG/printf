#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, wid, prec, len, buffer_t = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_t++] = format[i];
			if (buffer_t == BUFF_SIZE)
				print_buffer(buffer, &buffer_t);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_t);
			flags = get_flags(format, &i);
			wid = get_width(format, &i, args);
			prec = get_precision(format, &i, args);
			len = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
					flags, wid, prec, len);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buffer_t);
	va_end(args);
	return (printed_chars);
}



/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buffer_t)
{
	if (*buffer_t > 0)
		write(1, &buffer[0], *buffer_t);
	*buffer_t = 0;
}
