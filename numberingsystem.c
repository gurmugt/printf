#include "main.h"

/** Functions that prints numbering system */


/**
 * printBinary - to Print unsigned number
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printBinary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
n = va_arg(types, unsigned int);
m = 2147483648;
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}



/**
 * printOctal - to Print unsigned number in octal
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printOctal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convertSizeUnsignd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (writeUnsignd(0, i, buffer, flags, width, precision, size));
}



/**
 * printHexadecimal - to Print unsigned number in hexadecimal
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printHexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (printHexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}


/**
 * printHexaUpper - to Print unsigned number in upper hexadecimal
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printHexaUpper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (printHexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * printHexa - Prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: to map Array of values
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @flag_ch: flag of characters
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printHexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convertSizeUnsignd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (writeUnsignd(0, i, buffer, flags, width, precision, size));
}
