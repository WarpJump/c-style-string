#include <stdio.h>
#include <stdlib.h>

/*!
\file
\brief Header file with declarations of my string library
*/

/*!
\brief Default number of object to be allocated if no info specified
*/
static const size_t kDefaultAllocSize = 16;

/*!
\brief Prints null-terminated string in standart output

\param str - string to be printed

\return return EOF if given nullptr as pointer to string, or if error occured in
stdout, 0 otherwise

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

/*!
    returns length of string without terminating character
*/

size_t MyStrlen(const char *str);

/*!
\brief Copyes one string to the beginning of another

Copies the null-terminated byte string pointed to by src, including the null
terminator, to the character array whose first element is pointed to by dest.

\param dest - target. Rointer to the character array to write to
\param src - source. Pointer to the null-terminated byte string to copy from

\return returns pointer to the dest in success, or nullptr in failure

*/

char *MyStrcpy(char *dest, const char *src);

/*!
\brief Copyes at most count elements from one string to beginning of another
\param dest - target. Pointer to the character array to copy to
\param src - source. Pointer to the character array to copy from
\param count - max number of copyed chars
\return returns pointer to the dest in success, or nullptr in failure
 Copies at most count characters of the character array pointed to by src,
including null character
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

/*!
\brief Reads at most count - 1 characters from the given file stream and stores
them in the character array pointed to by str. \return Return pointer to as
tring on success, or nullptr in failure*/

char *MyFgets(char *str, int count, FILE *stream);

char *MyStrdup(const char *src);

/*!
\brief Reads from file unti; delimiter symbol occures and stores in string
buffer pointed to by lineptr \param lineptr - pointer to a string of initial
buffer or to a null pointer \param n - pointer to the size of the initial buffer
\param delimiter - delimiter character
\param stream - input stream, function return -1 if equal to nullptr

\return size of the buffer if success, -1 otherwise
*/

ssize_t MyGetdelim(char **lineptr, size_t *capacity, int delimiter,
                   FILE *stream);

/*!
\brief Reads symbols from stream untin newline symbol occures as if
getdelim(lineptr, n, '\n', stream)

\return size of the buffer if success, -1 otherwise
*/

ssize_t MyGetline(char **lineptr, size_t *capacity, FILE *stream);

/*!
\brief Finds first occurance of substring in string.
\param str - pointer to the null-terminated string to examine.
\param substr - pointer to the null-terminated string to search for.

\return Pointer to the first character of the found substring in str. Returns
nullptr if errors orrured.
*/

char *MyStrstr(const char *str, const char *substr);

/*!
\brief Prefix function requared for knutt-moris-pratt algorythm
\param string - string where to search refixes and postfixes
\param previous_prefix_postfix - array where at i-th position stored length of
longest prefix and postfix of string
\param n - length of string 'string'
*/

void PrefixFunction(const char *string, size_t *previous_prefix_postfix,
                    size_t n);

/*!
 \brief Compares two strings until their null terminating symbol.
 Needed for testing
*/

bool AreStrMatches(const char *first, const char *second);

/*!
\brief Compares first n symbols of two strings
\return Returns false if first n symbols of strings not match or nullptr
received, true otherwise
*/

bool CompareStrings(char *longest, char *shortest, size_t n);
