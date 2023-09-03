#include "main.h"

/** Functions related to printing Integers */


/**
 * printInt - to Print integer
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printInt(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convertSizeNumber(n, size);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (writeNumber(is_negative, i, buffer, flags, width, precision, size));
}



/**
 * printUnsigned - to Print unsigned number
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */

int printUnsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convertSizeUnsignd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (writeUnsignd(0, i, buffer, flags, width, precision, size));
}

/************************* WRITE NUMBER *************************/
/**
 * writeNumber - Prints a string
 * @is_negative: argument list
 * @ind: char type
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */

int writeNumber(int is_negative, int ind, char buffer[],

int flags, int width, int precision, int size)

{

int length = BUFF_SIZE - ind - 1;

char padd = ' ', extra_ch = 0;



UNUSED(size);



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';

if (is_negative)

extra_ch = '-';

else if (flags & F_PLUS)

extra_ch = '+';

else if (flags & F_SPACE)

extra_ch = ' ';



return (writeNum(ind, buffer, flags, width, precision,

length, padd, extra_ch));

}

 /**
 * writeNum - to Write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @prec: input Precision
 * @length: input Size
 * @padd: Padding character
 * @extra_c: Extra character
 * Return: number of characters written
 */

int writeNum(int ind, char buffer[],

int flags, int width, int prec,

int length, char padd, char extra_c)

{
int i, padd_start = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}



/**
 * writeUnsignd - to Write  unsigned number
 * @is_negative: to indicate if the number is negative
 * @ind: index in which the buffer starts
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of  characters written
 */

int writeUnsignd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size)

{
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_negative);

UNUSED(size);

if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);
if (precision > 0 && precision < length)
padd = ' ';

while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}
else
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
