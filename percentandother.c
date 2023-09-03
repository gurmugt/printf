#include "main.h"
/*Function to print percent and other useful functions*/

/**
 * printPercent - to Print %
 * @types: arguments list
 * @buffer: array of buffer
 * @flags:  to Calculate active flags
 * @width: input Width
 * @precision: input Precision
 * @size: input Size
 * Return: number of printed chars
 */
int printPercent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}


/**
 * appendHexaCode - to Append ASCII in hexadecimal code to buffer
 * @buffer: array of buffer
 * @i: index where appending starts
 * @ascii_code: ASSCI CODE
 * Return: 3 Always
 */

int appendHexaCode(char ascii_code, char buffer[], int i)

{

char map_to[] = "0123456789ABCDEF";


if (ascii_code < 0)

ascii_code *= -1;



buffer[i++] = '\\';

buffer[i++] = 'x';



buffer[i++] = map_to[ascii_code / 16];

buffer[i] = map_to[ascii_code % 16];



return (3);

}



/**
 * isDigit - to Verify if a char is a digit
 * @c: Character to be evaluated
 *
 * Return: 1 if c is a digit, else 0
 */

int isDigit(char c)

{

if (c >= '0' && c <= '9')

return (1);



return (0);

}



/**
 * convertSizeNumber - to Cast number to specified size
 * @num: number gonna casted.
 * @size: number to indicate cast type
 *
 * Return: num
 */

long int convertSizeNumber(long int num, int size)

{

if (size == S_LONG)

return (num);

else if (size == S_SHORT)

return ((short)num);



return ((int)num);

}



/**
 * convertSizeUnsignd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: input size
 * Return: Casted value of num
 */

long int convertSizeUnsignd(unsigned long int num, int size)

{

if (size == S_LONG)

return (num);

else if (size == S_SHORT)

return ((unsigned short)num);



return ((unsigned int)num);

}
