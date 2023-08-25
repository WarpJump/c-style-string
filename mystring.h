#include <stdio.h>


int puts(const char* str);

char *strchr(const char *str, int ch );

size_t strlen( const char *str );

char *strcpy( char *dest, const char *src);

char *strncpy( char *dest, const char *src, size_t count );

char *strcat( char *dest, const char *src );

char *strncat( char *dest, const char *src, size_t count );

char* fgets(char* str, int count, FILE* stream);

char* strdup(const char* src);

ssize_t getline(char **lineptr, size_t *n, FILE* stream);

bool AreStrMatches(const char* first, const char* second);

