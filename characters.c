#include "main.h"

/********* Functions related to printing characters ***********/

/**
 * printChar - to Print a char
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printChar(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (writeChar(c, buffer, flags, width, precision, size));
}



/**
 * printString - Prints a string
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printString(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}

}
return (write(1, str, length));
}


/**
 * writeChar - to Print string
 * @c: types of char
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */

int writeChar(char c, char buffer[],

int flags, int width, int precision, int size)

{

int i = 0;

char padd = ' ';

UNUSED(precision);

UNUSED(size);

if (flags & F_ZERO)
padd = '0';

buffer[i++] = c;
buffer[i] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < width - 1; i++)
buffer[BUFF_SIZE - i - 2] = padd;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}



/**
 * printReverse - to Print string in reverse
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printReverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
return (count);
}



/**
 * printRot13String - to Print string in rot13
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printRot13String(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
