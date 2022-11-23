#include "main.h"

/**
 * _printf - function to print according to format
 * @format: input characters to be printed
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);
	ret = run_printf(format, args, output);



	return (ret);
}
