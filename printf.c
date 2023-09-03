#include "main.h"

/** printf function to print chars according their format */
/**
 * handlePrint - to Print an argument based on format
 * @fmt: format of string gonna printed
 * @list: list of arguments gonna printed.
 * @ind: index
 * @buffer: array of buffer
 * @flags: to Calculate active flags
 * @width: input width.
 * @precision: Precision
 * @size: input Size
 * Return: 1 or 2
 */
int handlePrint(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, unknow_len = 0, printed_chars = -1;
fmt_t fmt_types[] = {
{'c', printChar}, {'s', printString}, {'%', printPercent},
{'i', printInt}, {'d', printInt}, {'b', printBinary},
{'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
{'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
{'r', printReverse}, {'R', printRot13String}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*ind] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}

void printBuffer(char buffer[], int *buff_ind);
/**
 * _printf - function like Printf in stdioh
 * @format: type of format
 * Return: the chars printed
 */
int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buff_ind = 0;

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

printBuffer(buffer, &buff_ind);


printed_chars++;

}

else

{

printBuffer(buffer, &buff_ind);

flags = getFlags(format, &i);

width = getWidth(format, &i, list);

precision = getPrecision(format, &i, list);

size = getSize(format, &i);

++i;

printed = handlePrint(format, &i, list, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



printBuffer(buffer, &buff_ind);



va_end(list);



return (printed_chars);

}



/**
 * printBuffer - to Print the contents of the buffer if ther is
 * @buffer: array of characters
 * @buff_ind: index to represent specific place in the bufer
 */

void printBuffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

}
