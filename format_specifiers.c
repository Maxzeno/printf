#include "main.h"
/**
 * print_char - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_integer(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}

/**
 * unsigned_integer - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}

/**
 * print_big_s - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_big_s(va_list list)
{
        int i, count = 0;
        char *str;

        str = va_arg(list, char *);
        if (str == NULL)
                str = "(null)";
        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] < 32 || str[i] >= 127)
                {
                        count += _write_char('\\');
                        count += _write_char('x');
                        count += print_hex(str[i], 2);
                }
                else
                {
                        _write_char(str[i]);
                        count++;
                }
        }
        return (count);
}

/**
 * print_hex_s - Prints an unsigned int in hexadecimal format
 * @num: The number to print
 * @padding: The minimum number of digits to print
 * Return: The number of characters printed
 */

int print_hex_s(unsigned int num, int padding)
{
        int i, count = 0;
        char hex_chars[] = "0123456789ABCDEF";
        char hex_num[padding + 1];

        hex_num[padding] = '\0';
        for (i = padding - 1; i >= 0; i--)
        {
                hex_num[i] = hex_chars[num % 16];
                num /= 16;
        }
        for (i = 0; i < padding; i++)
        {
                _write_char(hex_num[i]);
                count++;
        }
        return (count);
}
