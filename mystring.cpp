// TODO my_puts my_strchr my_strlen my_strcpy my_strncpy my_strcat my_strncat
// my_fgets my_strdup my_getline

/*!
\file
\brief File with definition of smy c-string library
*/

#include "mystring.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "myasserts.h"

#ifndef NDEBUG
FILE *debugfile = fopen("logs.txt", "w");
#endif

int MyPuts(const char *str) {
  ASSERT_POINTER_NOT_NULL(str, EOF);

  int ret_value = 0;

  while ((*str != '\0') && (ret_value != EOF)) {
    ret_value = putchar(*str);
    ++str;
  }

  if (ret_value == EOF) {
    return EOF;
  }
  putchar('\n');
  return 0;
}

char *MyStrchr(const char *str, int ch) {
  ASSERT_POINTER_NOT_NULL(str, nullptr);

  while (*str != ch && *str != '\0') {
    ++str;
  }
  if (*str == ch) {
    return const_cast<char *>(str);
  }
  return nullptr;
}

size_t MyStrlen(const char *str) {
  ASSERT_POINTER_NOT_NULL(str, 0);

  size_t size = 0;
  char *current = const_cast<char *>(str);
  while (*current != '\0') {
    ++current;
  }
  return static_cast<size_t>(current - str);
}

char *MyStrcpy(char *dest, const char *src) {
  ASSERT_POINTER_NOT_NULL(dest, nullptr);
  ASSERT_POINTER_NOT_NULL(src, nullptr);
  ASSERT_POINTERS_NOT_EQUAL(dest, src, nullptr);

  char *old_dest = dest;
  while (*src != '\0') {
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest = *src;
  return old_dest;
}

char *MyStrncpy(char *dest, const char *src, size_t count) {
  ASSERT_POINTER_NOT_NULL(dest, nullptr);
  ASSERT_POINTER_NOT_NULL(src, nullptr);
  ASSERT_POINTERS_NOT_EQUAL(dest, src, nullptr);

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

char *MyStrcat(char *dest, const char *src) {
  ASSERT_POINTER_NOT_NULL(dest, nullptr);
  ASSERT_POINTER_NOT_NULL(src, nullptr);
  ASSERT_POINTERS_NOT_EQUAL(dest, src, nullptr);

  size_t dest_size = MyStrlen(dest);
  MyStrcpy(dest + dest_size, src);
  return dest;
}

char *MyStrncat(char *dest, const char *src, size_t count) {
  ASSERT_POINTER_NOT_NULL(dest, nullptr);
  ASSERT_POINTER_NOT_NULL(src, nullptr);
  ASSERT_POINTERS_NOT_EQUAL(dest, src, nullptr);

  size_t dest_size = MyStrlen(dest);
  MyStrncpy(dest + dest_size, src, count);
  return dest;
}

char *MyFgets(char *str, int count, FILE *stream) {
  ASSERT_POINTER_NOT_NULL(str, nullptr);
  ASSERT_POINTER_NOT_NULL(stream, nullptr);

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

char *MyStrdup(const char *src) {
  ASSERT_POINTER_NOT_NULL(src, nullptr);

  const size_t kSize = MyStrlen(src);
  ASSERT_ALLOCALION_SIZE_NOT_ZERO(kSize, nullptr);
  char *duplicate = reinterpret_cast<char *>(calloc(kSize, sizeof(char)));
  MyStrcpy(duplicate, src);

  return duplicate;
}

ssize_t MyGetdelim(char **lineptr, size_t *capacity, int delimiter,
                   FILE *stream) {
  ASSERT_POINTER_NOT_NULL(stream, -1);
  char letter = '\n';
  size_t stored = 0;
  size_t buffer = 0;

  if (*lineptr == nullptr) {
    buffer = kDefaultAllocSize;
    *lineptr =
        reinterpret_cast<char *>(calloc(kDefaultAllocSize, sizeof(char)));
    ASSERT_POINTER_NOT_NULL(lineptr, -1);
    capacity = &buffer;
  }

  while ((letter = fgetc(stream)) != delimiter) {
    if (stored + 1 > *capacity) {
      *capacity = 2 * (stored + 1);

      *lineptr = reinterpret_cast<char *>(realloc(*lineptr, *capacity));
      ASSERT_POINTER_NOT_NULL(lineptr, -1);

    }
    *(*lineptr + stored) = letter;
    ++stored;
  }

  *(*lineptr + stored) = delimiter;
  *(*lineptr + stored + 1) = '\0';

  return stored;
}

ssize_t MyGetline(char **lineptr, size_t *capacity, FILE *stream) {
  return MyGetdelim(lineptr, capacity, '\n', stream);
}

bool CompareStrings(char *longest, char *shortest, size_t n) {
  ASSERT_POINTER_NOT_NULL(longest, false);
  ASSERT_POINTER_NOT_NULL(shortest, false);

  for (size_t i = 0; i <= n; ++i) {
    if (*shortest == '\0') {
      return true;
    }
    if (*shortest != *longest) {
      return false;
    }
    ++shortest;
    ++longest;
  }
  return true;
}

// TODO Boyer-Moore

// hash-function implementation

char *MyStrstr(const char *str, const char *substr) {
  ASSERT_POINTER_NOT_NULL(str, nullptr);
  ASSERT_POINTER_NOT_NULL(substr, nullptr);
  
  char *str_proposal = const_cast<char *>(str);

  // prime numbers for hash functions
  static const size_t kBase = 263;
  static const size_t kPrimeNumber = 1073676287;

  // hash value for substring
  size_t substr_hash = 0;
  // hash value for {length} chars of main string
  size_t str_hash = 0;
  size_t length = 0;

  size_t max_base = 1;

  while (substr[length] != '\0') {
    // calculating hash value for substring
    substr_hash = substr_hash * kBase % kPrimeNumber + substr[length];
    substr_hash %= kPrimeNumber;

    // calculating hash value for first strlen(substring) chars of main string

    str_hash = str_hash * kBase % kPrimeNumber + str[length];
    str_hash %= kPrimeNumber;

    ++length;
  }

  // highest digit of the number in base = kBase notation
  for (int i = 1; i < length; ++i) {
    max_base *= kBase;
    max_base %= kPrimeNumber;
  }

  // pointer to first not hashed char of main string

  str_proposal += length;

  int count = 0;
  while (*str_proposal != '\0') {
    if (str_hash == substr_hash) {
      if (CompareStrings(str_proposal - length, const_cast<char *>(substr),
                         length)) {
        return str_proposal - length;
      }
    } else {
      // recalculating hash

      // removing the oldest char from the end
      str_hash += kPrimeNumber;
      str_hash -= ((*(str_proposal - length)) * max_base % kPrimeNumber);
      str_hash %= kPrimeNumber;

      // adding new char to the front
      str_hash = str_hash * kBase % kPrimeNumber;
      str_hash = (str_hash + *str_proposal) % kPrimeNumber;
    }
    ++str_proposal;
    ++count;
  }
  return nullptr;
}

// requared for Knuth–Morris–Pratt algorithm

void PrefixFunction(const char *string, size_t *previous_prefix_postfix,
                    size_t n) {
  previous_prefix_postfix[0] = 0;
  for (size_t str_proposal = 1; str_proposal < n; ++str_proposal) {
    char edge = string[str_proposal];
    size_t postfix_len = previous_prefix_postfix[str_proposal - 1];
    while (postfix_len != 0 && (edge != string[postfix_len])) {
      postfix_len = previous_prefix_postfix[postfix_len - 1];
    }

    if (edge == string[postfix_len]) {
      postfix_len += 1;
    }

    previous_prefix_postfix[str_proposal] = postfix_len;
  }
}

// Knuth–Morris–Pratt algorithm

/*char *MyStrstr(const char *str, const char *substr) {
  size_t str_len = MyStrlen(str);
  if (str_len == 0) {
    return nullptr;
  }

  size_t *prefixes =
      reinterpret_cast<size_t *>(calloc(str_len, sizeof(size_t)));
  PrefixFunction(substr, prefixes, str_len);
  size_t str_proposal = 0;
  size_t eq_completed = 0;
  size_t substr_proposal = 0;

  while (str[str_proposal] != '\0') {
    while (str[str_proposal + eq_completed] == substr[substr_proposal]) {
      ++eq_completed;
      ++substr_proposal;
      if (substr[substr_proposal] == '\0') {
        free(prefixes);
        return const_cast<char *>(str) + str_proposal;
      }
    }
    substr_proposal = prefixes[substr_proposal];

    ++str_proposal;
  }
  free(prefixes);

  return nullptr;
}*/

// naive O(n^2) algorythm

/*char *my_strstr(const char *str, const char *substr) {
  char *orig_begin = const_cast<char *>(str);

  while (*orig_begin != '\0') {
    if (*orig_begin == *substr) {
      char *orig_runner = orig_begin;
      char *substr_runner = const_cast<char *>(substr);
      bool is_found = true;
      while ((*orig_runner != '\0') && (*substr_runner != '\0')) {
        if (*orig_runner != *substr_runner) {
          is_found = false;
          break;
        }
        ++orig_runner;
        ++substr_runner;
      }
      if (is_found &&
          ((*orig_runner != '\0') || (*orig_runner == *substr_runner))) {
        return orig_begin;
      }
    }
    ++orig_begin;
  }
  return nullptr;
}*/

bool AreStrMatches(const char *first, const char *second) {
  assert(first != nullptr);
  assert(second != nullptr);

  while (*first != '\0' && *second != '\0') {
    if (*first != *second) {
      return false;
    }
    ++first;
    ++second;
  }
  return *first == *second;
}
