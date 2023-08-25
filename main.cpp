#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"

void TestLength() {
  const char kExample1[8] = "amongus";  // will not be modified
  assert(strlen("cucumber") == 8);
  assert(strlen(kExample1) ==
         7);  // because example1 has null terminator of its 8th element

  assert(strchr(kExample1, 'n') - kExample1 == 3);
}

void TestCopy() {
  const char kExample1[8] = "amongus";

  char test1[8] = "red sus";
  strcpy(test1, kExample1);
  assert(AreStrMatches(test1,
                      kExample1));  // expected test1 = example1 = "amongus"

  const char kExample2[16] = "amongus amongus";
  char test2[16] = "song of amongus";
  strncpy(test2, kExample1, 7);
  assert(AreStrMatches(test2,
                      kExample2));  // expected test2 = "amongus amongus"
}

void TestConcatenation() {
  const char kExample1[8] = "amongus";

  char test3[20] = "red is not imposter";
  const char kExample3[20] = "red is amongus";
  test3[7] = '\0';
  strcat(test3, kExample1);
  assert(AreStrMatches(test3, kExample3));  // expected test3 = "red is amongus"

  const char kExample4[20] = "red is amongus sus";
  strncat(test3, " sus", 5);
  assert(AreStrMatches(test3,
                      kExample4));  // expected test3 = "red is amongus rsus"
}

void TestFileRead() {
  FILE* testfile = fopen("test.txt", "r");
  const char kExample5[7] = "songus";
  char test5[15];
  fgets(test5, 7, testfile);
  assert(AreStrMatches(test5, kExample5));
  fclose(testfile);

  testfile = fopen("test.txt", "r");
  char test6[16];
  fgets(test6, 16, testfile);
  assert(strlen(test6) == 15);
  assert(test6[14] == '\n');
  assert(test6[15] == '\0');
}

void TestDynamicCopy() {
  char statical[40] = "nwljbknwnkbankn dafn saknwaknDkjkerbknn";

  char* dynamical = strdup(statical);

  assert(strlen(dynamical) == strlen(statical));

  assert(AreStrMatches(statical, dynamical));
  free(dynamical);
}

int main() {
  TestLength();

  TestCopy();

  TestConcatenation();

  TestFileRead();

  TestDynamicCopy();

  printf("test ok\n");
}