#include <stdio.h>
#include <stdlib.h>

static const size_t kDefaultAllocSize = 16;

int MyPuts(const char* str);

char *MyStrchr(const char *str, int ch );

size_t MyStrlen( const char *str );

char *MyStrcpy( char *dest, const char *src);

char *MyStrncpy( char *dest, const char *src, size_t count );

char *MyStrcat( char *dest, const char *src );

char *MyStrncat( char *dest, const char *src, size_t count );

char* MyFgets(char* str, int count, FILE* stream);

char* MyStrdup(const char* src);

ssize_t MyGetdelim(char **lineptr, size_t *capacity, int delimiter, FILE *stream);

ssize_t MyGetline(char **lineptr, size_t *capacity, FILE* stream);

char *MyStrstr( const char *str, const char *substr );

void PrefixFunction(const char *string, size_t *previous_prefix_postfix, size_t n);


bool AreStrMatches(const char* first, const char* second);

