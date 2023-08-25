#include <assert.h>
#include <stdio.h>

#include "mystring.h"

#define test(func)            \
  ... if (my##func == func) { \
    // test passed      \
    }

void TestLength() {
  const char kExample1[8] = "amongus";  // will not be modified
  assert(MyStrlen("cucumber") == 8);
  assert(MyStrlen(kExample1) ==
         7);  // because example1 has null terminator of its 8th element

  assert(MyStrchr(kExample1, 'n') - kExample1 == 3);
}

void TestCopy() {
  const char kExample1[8] = "amongus";

  char test1[8] = "red sus";
  MyStrcpy(test1, kExample1);
  assert(AreStrMatches(test1,
                       kExample1));  // expected test1 = example1 = "amongus"

  const char kExample2[16] = "amongus amongus";
  char test2[16] = "song of amongus";
  MyStrncpy(test2, kExample1, 7);
  assert(AreStrMatches(test2,
                       kExample2));  // expected test2 = "amongus amongus"
}

void TestConcatenation() {
  const char kExample1[8] = "amongus";

  char test3[20] = "red is not imposter";
  const char kExample3[20] = "red is amongus";
  test3[7] = '\0';
  MyStrcat(test3, kExample1);
  assert(AreStrMatches(test3, kExample3));  // expected test3 = "red is amongus"

  const char kExample4[20] = "red is amongus sus";
  MyStrncat(test3, " sus", 5);
  assert(AreStrMatches(test3,
                       kExample4));  // expected test3 = "red is amongus rsus"
}

void TestFileRead() {
  FILE* testfile = fopen("test.txt", "r");
  const char kExample5[7] = "songus";
  char test5[15];
  MyFgets(test5, 7, testfile);
  assert(AreStrMatches(test5, kExample5));
  fclose(testfile);

  testfile = fopen("test.txt", "r");
  char test6[16];
  MyFgets(test6, 16, testfile);
  assert(MyStrlen(test6) == 15);
  assert(test6[14] == '\n');
  assert(test6[15] == '\0');
}

void TestDynamicCopy() {
  char statical[40] = "nwljbknwnkbankn dafn saknwaknDkjkerbknn";

  char* dynamical = MyStrdup(statical);

  assert(MyStrlen(dynamical) == MyStrlen(statical));

  assert(AreStrMatches(statical, dynamical));
  free(dynamical);
}

void TestDynamicLine() {
  FILE* testfile = fopen("test.txt", "r");
  char* line = reinterpret_cast<char*>(calloc(10, sizeof(char)));
  size_t buffer = 10;
  MyGetline(&line, &buffer, testfile);

  const char kExample6[16] = "songus amongus\n";
  assert(MyStrlen(line) == MyStrlen(kExample6));
  assert(AreStrMatches(line, kExample6));

  free(line);
}

void TestSTRSTR() {
  char example[20] = "qjbejbjEBJVBEWJVNKW";
  char substr[5] = "BJVB";
  char* match = MyStrstr(example, substr);
  assert(match != nullptr);
  assert((match - example) == 8);
}

int main() {
  TestLength();

  TestCopy();

  TestConcatenation();

  TestFileRead();

  TestDynamicCopy();

  TestDynamicLine();

  TestSTRSTR();

  printf("test ok\n");
}