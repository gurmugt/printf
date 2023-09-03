#include "main.h"

/** Function to print pointers non printable characters */

/**
 * writePointer - to Write memory address
 * @buffer: array of buffer
 * @ind: Index at which the number starts on the buffer
 * @length: input Size
 * @width: input Width
 * @flags:  to Calculate active flags
 * @padd: Char representing the padding character
 * @extra_c: Char representing for extra char
 * @padd_start: Index where padding character starts
 * Return: number of printed chars
 */

int writePointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start)

{
int i;

if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}


/**
 * isPintable - to Evaluate if a char is printable
 * @c: input Character
 *
 * Return: 1 if c is printable, else 0
 */

int isPintable(char c)

{

if (c >= 32 && c < 127)

return (1);


return (0);

}



/**
 * printPointer - to Print the value of a pointer
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printPointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "NULL", 4));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long) addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;

return (writePointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}



/**
 * printNonPrintable - to Print ASCII codes in hexadecimal
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printNonPrintable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
if (isPintable(str[i]))
buffer[i + offset] = str[i];
else
offset += appendHexaCode(str[i], buffer, i + offset);
i++;
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
}
