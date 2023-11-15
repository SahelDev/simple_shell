#include "shell.h"

/**
 * _printf - prints strings with formatted variables
 * @format: the string to format and print
 *
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int chk = 0;
	int retcount = 0;
	va_list args;
	fmt fmtspec[] = {
		{"%", chk_fmt},
		{"\\", chk_fmt},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == *(fmtspec[0].ltr))
		{
			chk += fmtspec[0].type(&args, format, i);
			if (chk == -1)
				return (-1);
			retcount += chk;
			i++;
			while (format[i] == ' ')
				i++;
			chk = 1;
		}
		if (chk == 0)
		{
			_putchar(format[i]);
			retcount++;
		}
		chk = 0;
		i++;
	}

	va_end(args);
	return (retcount);
}

/**
 * chk_fmt - checks the format modifer
 * @args: argument pointer
 * @format: the string
 * @i: the location of the modifer
 *
 * Return: count of anything printed
 */
int chk_fmt(va_list *args, const char *format, int i)
{
	int j = 0, x = 0;
	fmt fmtmods[] = {
		{"s", pr_str},
		{"d", pr_dgt},
		{"i", pr_dgt},
		{NULL, NULL}
	};

	i++;
	if (format[i] == ' ')
	{
		while (format[i] == ' ')
			i++;
	}
	if (format[i] == '%')
	{
		_putchar('%');
		return (1);
	}
	if (format[i] == 'n')
	{
		_putchar('\n');
		return (1);
	}
	while (fmtmods[j].type != NULL && *(fmtmods[j].ltr) != format[i])
	{
		j++;
	}
	if (fmtmods[j].type == NULL)
	{
		return (-1);
	}
	x = fmtmods[j].type(args);
	return (x);
}

/**
 * get_digits - gets digits
 * @n: int to get digits from
 */
void get_digits(int n)
{
	if (n > 0)
		get_digits((n / 10));
	if (n != 0)
	{
		_putchar('0' + (n % 10));
	}
}
/**
 * pr_dgt - prints digit passed from _printf
 * @args: argument pointer
 *
 * Return: count of digits and signs printed
 */
int pr_dgt(va_list *args)
{
	int rc = 0;
	int n = va_arg(*args, int);
	int x = n;
	int ld = 1;

	if (x < 0)
		x *= -1;

	while (x > 0)
	{
		x /= 10;
		rc++;
	}
	if (n < 0)
	{
		_putchar('-');
		rc++;
		ld = n % 10;
		n = n / -10;
	}
	else if (n == 0)
	{
		_putchar('0');
		return (rc);
	}
	get_digits(n);
	if (ld < 0)
	{
		_putchar('0' - ld);
	}
	return (rc);
}
