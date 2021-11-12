#include "main.h"
int _putchar(char c)
{
	return (write(1,&c,1));
}
int _printf(const char *format, ...)
{
	va_list arg;
	int i, fun = 0;
	int nbPrinted;
	i = 0;
	nbPrinted = 0;
	if( !format || (format[0] == '%' && format[1] == '\0') )
	{
		return -1;
	}
	va_start(arg,format);
	while( *(format + i)  && format)
	{
		if( *(format + i) != '%' )
		{
			_putchar(*(format + i));
			nbPrinted++;
		}
		if (*(format + i) == '%')
		{
			fun = get_func(*(format + (i + 1)), arg);
			if (fun != 0)
			{
				nbPrinted =  nbPrinted + fun;
				i = i + 2;
				continue;


			}
			if (*(format + (i + 1)) == '\0')
			{
				_putchar(*(format + i));
				nbPrinted++;
			}
		}
	i++;
	}
	va_end(arg);
	return nbPrinted;
}
