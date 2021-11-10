#include "main.h"
int _putchar(char c)
{
	return (write(1,&c,1));
}
int _printf(const char *format, ...)
{
	va_list arg;
	char * currentLetter;
	int i;
	int nbPrinted;
	i = 0;
	nbPrinted = 0;
	if( !format || (format[0] == '%' && format[1] == '\0') )
	{
		return -1;
	}
	va_start(arg,format);
	while( *(format + i)  != '\0' )
	{
	if( *(format + i) != '%' )
	{
		_putchar(*(format + i));
		nbPrinted++;
	}
	else
	{
	switch (*(format + i + 1))
	{
		case 'c':
			_putchar( (char) va_arg(arg,int));
			nbPrinted++;
		break;
		case 's':
			currentLetter =  va_arg(arg,char *);
			while ( (*currentLetter) != '\0')
			{
				_putchar(*currentLetter);
				nbPrinted++;
				currentLetter++;
			}
			break;
	}
	i++;		
	}
	i++;
	}
	va_end(arg);
	return nbPrinted;
}
