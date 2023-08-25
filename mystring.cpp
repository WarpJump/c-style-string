// TODO puts strchr strlen strcpy strncpy strcat strncat fgets strdup getline

#include "mystring.h"

#include <stdlib.h>

int puts(const char *str) {
  int ret_value = 0;
  while ((*str != '\0') && (ret_value != EOF)) {
    ret_value = putchar(*str);
    ++str;
  }
  if (ret_value == EOF) {
    // TODO set error indicator
    return EOF;
  }
  putchar('\n');
  return 0;
}

/*!
\descr finds the first occurance of ch
*/

char *strchr(const char *str, int ch) {
  while (*str != ch && *str != '\0') {
    ++str;
  }
  if (*str == ch) {
    return const_cast<char *>(str);
  }
  return nullptr;
}

/*!
    returns length of string without terminating character
*/

size_t strlen(const char *str) {
  size_t size = 0;
  char *current = const_cast<char *>(str);
  while (*current != '\0') {
    ++current;
  }
  return static_cast<size_t>(current - str);
}

char *strcpy(char *dest, const char *src) {
  char *old_dest = dest;
  while (*src != '\0') {
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest = *src;
  return old_dest;
}

char *strncpy(char *dest, const char *src, size_t count) {
  char *old_dest = dest;
  size_t num_of_already_copied = 0;
  while ((*src != '\0') && (num_of_already_copied < count)) {
    *dest = *src;
    ++src;
    ++dest;
    ++num_of_already_copied;
  }
  if ((*src == '\0') && (num_of_already_copied < count)) {
    *dest = *src;
  }
  return old_dest;
}

char *strcat(char *dest, const char *src) {
  size_t dest_size = strlen(dest);
  strcpy(dest + dest_size, src);
  return dest;
}

char *strncat(char *dest, const char *src, size_t count) {
  size_t dest_size = strlen(dest);
  strncpy(dest + dest_size, src, count);
  return dest;
}

/*!
Reads at most count - 1 characters from the given file stream and stores them in
the character array pointed to by str.*/

char *fgets(char *str, int count, FILE *stream) {
  char *old_str = str;
  int copyed = 1;
  char letter = '\n';
  while ((copyed < count) && ((letter = fgetc(stream)) != '\n') &&
         (letter != EOF)) {
    *str = letter;
    ++str;
    ++copyed;
  }
  if (letter == EOF) {
    return nullptr;
  }
  if (letter == '\n') {
    *str = letter;
    ++str;
  }
  *str = '\0';

  return old_str;
}

char *strdup(const char *src) {
  const size_t kSize = strlen(src);
  char *duplicate = reinterpret_cast<char *>(calloc(kSize, sizeof(char)));
  strcpy(duplicate, src);
  return duplicate;
}

ssize_t getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream) {
  char letter = '\n';
  size_t stored = 0;
  size_t buffer = 0;

  if (*lineptr == nullptr) {
    *lineptr = reinterpret_cast<char *>(malloc(2));
    buffer = 2;
    n = &buffer;
  }

  while ((letter = fgetc(stream)) != delimiter) {
    if (stored + 1 > *n) {
      *lineptr = reinterpret_cast<char *>(realloc(*lineptr, 2 * (stored + 1)));
      *n = 2 * (stored + 1);
    }
    *(*lineptr + stored) = letter;
    ++stored;
  }
  *(*lineptr + stored) = delimiter;
  *(*lineptr + stored + 1) = '\0';

  return stored;
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
  return getdelim(lineptr, n, '\n', stream);
}

bool AreStrMatches(const char *first, const char *second) {
  while (*first != '\0' && *second != '\0') {
    if (*first != *second) {
      return false;
    }
    ++first;
    ++second;
  }
  return *first == *second;
}
