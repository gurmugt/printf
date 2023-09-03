#include "main.h"

/** Functions for specifiers */

/**
 * getPrecision - to Calculate the precision
 * @format: format of string in which to be printed
 * @i: list of arguments gonna printed.
 * @list: list of the arguments
 *
 * Return: Precision
 */
int getPrecision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (isDigit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (precision);
}


/**
 * getWidth - to Calculate the width
 * @format: Format of string in which to be printed
 * @i: list of arguments gonna printed.
 * @list: list of arguments.
 *
 * Return: Width
 */
int getWidth(const char *format, int *i, va_list list)
{
int curr_i;
int width = 0;
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (isDigit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (width);
}


/**
 * getSize - to Calculate the size to cast
 * @format: Format of string in which to printed
 * @i: list of arguments gonna printed.
 *
 * Return: Size
 */
int getSize(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;
if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;
if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}


/**
 * getFlags - to Calculate for active flags
 * @format: Formatted string gonna printed
 * @i: takes a parameter
 * Return: flags
 */
int getFlags(const char *format, int *i)
{
int j, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[curr_i] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
if (FLAGS_CH[j] == 0)
break;
}
*i = curr_i - 1;
return (flags);
}
