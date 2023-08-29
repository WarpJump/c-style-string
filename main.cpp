#include <assert.h>
#include <stdio.h>

#include "mystring.h"
#include "myasserts.h"
#include "string.h"

#include "mystack.h"

/*!
\file
\brief File with test functions for my c-string library
*/

void TestLength();
void TestCopy();
void TestConcatenation();
void TestFileRead();
void TestDynamicCopy();
void TestDynamicLine();
void TestSTRSTR();
void TestMyAsserts();

#ifndef NDEBUG
FILE *debugfile = fopen("logs.txt", "w");
#endif
BACKTRACE* backtrace;

int main() {
  backtrace =  BackTraceConstruct();

  TestLength();

  TestCopy();

  TestConcatenation();

  TestFileRead();

  TestDynamicCopy();

  TestDynamicLine();

  TestSTRSTR();
  TRACE {
    TestMyAsserts();
  }

  printf("test ok\n");

  BackTraceDestroy(backtrace);

  #ifndef NDEBUG
  fclose(debugfile);
  #endif
}

void TestLength() {
  const char kExample1[8] = "amongus";  // will not be modified
  assert(MyStrlen("cucumber") == strlen("cucumber"));
  assert(MyStrlen(kExample1) == strlen(kExample1));

  assert(MyStrchr(kExample1, 'n') == strchr(kExample1, 'n'));
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
  char ans3[20] = "red is not imposter";
  test3[7] = '\0';
  ans3[7] = '\0';


  MyStrcat(test3, kExample1);
  strcat(ans3, kExample1);
  assert(AreStrMatches(test3, ans3));  // expected test3 = "red is amongus"

  const char kExample4[20] = "red is amongus sus";
  MyStrncat(test3, " sus", 5);
  strncat(ans3,  " sus", 5);
  assert(AreStrMatches(test3,
                       kExample4));
  assert(AreStrMatches(test3,
                       ans3));  // expected test3 = "red is amongus rsus"
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
  size_t buffer = 10;
  char* line = reinterpret_cast<char*>(calloc(buffer, sizeof(char)));
  MyGetline(&line, &buffer, testfile);

  const char kExample6[16] = "songus amongus\n";
  assert(MyStrlen(line) == MyStrlen(kExample6));
  assert(AreStrMatches(line, kExample6));

  fclose(testfile);

  free(line);
}

void TestSTRSTR() {
  char example[20] = "qjbejbjEBJVBEWJVNKW";
  char substr[5] = "BJVB";
  char* match = MyStrstr(example, substr);
  assert(match != nullptr);
  assert((match - example) == 8);
}

void TestMyAsserts() { MyPuts(nullptr); }

