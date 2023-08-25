#include <stdio.h>
#include <stdlib.h>

/*!
\file
\brief Header file of my string functions
*/

/*!
\brief Default number of object to be allocated if no info specified
*/
static const size_t kDefaultAllocSize = 16;

/*!
\brief Prints null-terminated string in standart output

\param str - string to be printed

\return return EOF if error occured in stdout, 0 otherwise

Print every symbol of a string as if putc()
*/

int MyPuts(const char *str);

/*!
\brief Finds first occurance of char in given string

\param str - string to be examined
\param ch - symbol to be founded

\return return ns pointer to the first occurance

*/

char *MyStrchr(const char *str, int ch);

size_t MyStrlen(const char *str);

/*!
\brief Copyes one string to the beginning of another

Copies the null-terminated byte string pointed to by src, including the null
terminator, to the character array whose first element is pointed to by dest.

\param dest - target. Rointer to the character array to write to
\param src - source. Pointer to the null-terminated byte string to copy from
*/

char *MyStrcpy(char *dest, const char *src);

/*!
\brief Copyes at most count elements from one string to beginning of another
\param dest - target. Pointer to the character array to copy to
\param src - source. Pointer to the character array to copy from
\param count - max number of copyed chars

) Copies at most count characters of the character array pointed to by src
(including the terminating null character, but not any of the characters that
follow the null character) to character array pointed to by dest.
*/

char *MyStrncpy(char *dest, const char *src, size_t count);

/*!
\brief Concatenates one string to the end of another

\param src - source of chars to be copied
\param dest - target. First char from source will be copyed to the first
occurance of null terminator
*/

char *MyStrcat(char *dest, const char *src);

/*!
\brief Concatenates a certain amount of characters of one strings to the end of
another

*/

char *MyStrncat(char *dest, const char *src, size_t count);

char *MyFgets(char *str, int count, FILE *stream);

char *MyStrdup(const char *src);

ssize_t MyGetdelim(char **lineptr, size_t *capacity, int delimiter,
                   FILE *stream);

ssize_t MyGetline(char **lineptr, size_t *capacity, FILE *stream);

// Knuth–Morris–Pratt algorithm
/*!
\brief Finds first occurance of substring in string.
\param str - pointer to the null-terminated string to examine.
\param substr - pointer to the null-terminated string to search for.

\return Pointer to the first character of the found substring in str, or a null
pointer if such substring is not found. If substr points to an empty string, str
is returned.

Finds the first occurrence of the null-terminated byte string pointed to by
substr in the null-terminated byte string pointed to by str. The terminating
null characters are not compared.

*/

char *MyStrstr(const char *str, const char *substr);

void PrefixFunction(const char *string, size_t *previous_prefix_postfix,
                    size_t n);

bool AreStrMatches(const char *first, const char *second);
