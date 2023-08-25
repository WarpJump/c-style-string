// TODO my_puts my_strchr my_strlen my_strcpy my_strncpy my_strcat my_strncat fgets my_strdup my_getline

#include "mystring.h"

#include <stdlib.h>

int my_puts(const char *str) {
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

char *my_strchr(const char *str, int ch) {
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

size_t my_strlen(const char *str) {
  size_t size = 0;
  char *current = const_cast<char *>(str);
  while (*current != '\0') {
    ++current;
  }
  return static_cast<size_t>(current - str);
}

char *my_strcpy(char *dest, const char *src) {
  char *old_dest = dest;
  while (*src != '\0') {
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest = *src;
  return old_dest;
}

char *my_strncpy(char *dest, const char *src, size_t count) {
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

char *my_strcat(char *dest, const char *src) {
  size_t dest_size = my_strlen(dest);
  my_strcpy(dest + dest_size, src);
  return dest;
}

char *my_strncat(char *dest, const char *src, size_t count) {
  size_t dest_size = my_strlen(dest);
  my_strncpy(dest + dest_size, src, count);
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

char *my_strdup(const char *src) {
  const size_t kSize = my_strlen(src);
  char *duplicate = reinterpret_cast<char *>(calloc(kSize, sizeof(char)));
  my_strcpy(duplicate, src);
  return duplicate;
}

ssize_t my_getdelim(char **lineptr, size_t *capacity, int delimiter, FILE *stream) {
  char letter = '\n';
  size_t stored = 0;
  size_t buffer = 0;

  if (*lineptr == nullptr) {
    buffer = kDefaultAllocSize;
    *lineptr = reinterpret_cast<char *>(malloc(kDefaultAllocSize));
    capacity = &buffer;
  }

  while ((letter = fgetc(stream)) != delimiter) {
    if (stored + 1 > *capacity) {
      *capacity = 2 * (stored + 1); // TODO pass n to realloc, naming

      *lineptr = reinterpret_cast<char *>(realloc(*lineptr, *capacity));
    }
    *(*lineptr + stored) = letter;
    ++stored;
  }
  *(*lineptr + stored) = delimiter;
  *(*lineptr + stored + 1) = '\0';

  return stored;
}

ssize_t my_getline(char **lineptr, size_t *capacity, FILE *stream) {
  return my_getdelim(lineptr, capacity, '\n', stream);
}

char *my_strstr( const char *str, const char *substr ){
    char* orig_begin = const_cast<char*> (str);

    while(*orig_begin != '\0'){
        if(*orig_begin == *substr){
            char* orig_runner = orig_begin;
            char* substr_runner = const_cast<char*> (substr);
            bool is_found = true;
            while((*orig_runner != '\0') && (*substr_runner != '\0')){
                if(*orig_runner != *substr_runner){
                    is_found = false;
                    break;
                }
                ++orig_runner;
                ++substr_runner;
            }
            if(is_found && ((*orig_runner != '\0') || (*orig_runner == *substr_runner))){
                return orig_begin;
            }
        }
        ++orig_begin;
    }
    return nullptr;
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
