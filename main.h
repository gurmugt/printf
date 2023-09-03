#ifndef _main_h

#define _main_h

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>

#include <limits.h>

/** Description: structure, functions */

#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024



/**
 * struct fmt - Struct for format
 *
 * @fmt: Format
 * @fn: The function pointer
 */

struct fmt

{

char fmt;

int (*fn)(va_list, char[], int, int, int, int);

};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;



#define S_LONG 2

#define S_SHORT 1

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16


int _printf(const char *format, ...);

int handlePrint(const char *fmt, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* Funtions related to printing charcters */

int printChar(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printString(va_list types, char buffer[],

int flags, int width, int precision, int size);

int writeChar(char c, char buffer[],

int flags, int width, int precision, int size);

int printReverse(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printRot13String(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* Functions related to printing Integers */

int printInt(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printUnsigned(va_list types, char buffer[],

int flags, int width, int precision, int size);

int writeUnsignd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size);


int writeNumber(int is_positive, int ind, char buffer[],

int flags, int width, int precision, int size);

int writeNum(int ind, char bff[], int flags, int width, int precision,

int length, char padd, char extra_c);



/* Functions that prints numbering system */

int printBinary(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printOctal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printHexadecimal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printHexaUpper(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printHexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);



/* Function to print pointers non printable characters */

int isPintable(char);

int printNonPrintable(va_list types, char buffer[],

int flags, int width, int precision, int size);

int printPointer(va_list types, char buffer[],

int flags, int width, int precision, int size);

int writePointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start);


/*Function to print percent and other useful functions*/

int printPercent(va_list types, char buffer[],

int flags, int width, int precision, int size);

int appendHexaCode(char, char[], int);

int isDigit(char);

long int convertSizeNumber(long int num, int size);

long int convertSizeUnsignd(unsigned long int num, int size);


/* Functions for specifiers */

int getFlags(const char *format, int *i);

int getWidth(const char *format, int *i, va_list list);

int getPrecision(const char *format, int *i, va_list list);

int getSize(const char *format, int *i);







#endif /* _main_h */


