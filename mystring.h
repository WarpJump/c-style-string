#include <stdio.h>
#include <stdlib.h>

static const size_t kDefaultAllocSize = 16;

int my_puts(const char* str);

char *my_strchr(const char *str, int ch );

size_t my_strlen( const char *str );

char *my_strcpy( char *dest, const char *src);

char *my_strncpy( char *dest, const char *src, size_t count );

char *my_strcat( char *dest, const char *src );

char *my_strncat( char *dest, const char *src, size_t count );

char* fgets(char* str, int count, FILE* stream);

char* my_strdup(const char* src);

ssize_t my_getdelim(char **lineptr, size_t *capacity, int delimiter, FILE *stream);

ssize_t my_getline(char **lineptr, size_t *capacity, FILE* stream);

bool AreStrMatches(const char* first, const char* second);

