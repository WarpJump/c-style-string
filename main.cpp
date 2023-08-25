#include <assert.h>
#include <stdio.h>

#include "mystring.h"

#define test(func)          \
    ...                     \
    if (my##func == func) { \
        // test passed      \
    }

void TestLength() {
  const char kExample1[8] = "amongus";  // will not be modified
  assert(my_strlen("cucumber") == 8);
  assert(my_strlen(kExample1) ==
         7);  // because example1 has null terminator of its 8th element

  assert(my_strchr(kExample1, 'n') - kExample1 == 3);
}

void TestCopy() {
  const char kExample1[8] = "amongus";

  char test1[8] = "red sus";
  my_strcpy(test1, kExample1);
  assert(AreStrMatches(test1,
                      kExample1));  // expected test1 = example1 = "amongus"

  const char kExample2[16] = "amongus amongus";
  char test2[16] = "song of amongus";
  my_strncpy(test2, kExample1, 7);
  assert(AreStrMatches(test2,
                      kExample2));  // expected test2 = "amongus amongus"
}

void TestConcatenation() {
  const char kExample1[8] = "amongus";

  char test3[20] = "red is not imposter";
  const char kExample3[20] = "red is amongus";
  test3[7] = '\0';
  my_strcat(test3, kExample1);
  assert(AreStrMatches(test3, kExample3));  // expected test3 = "red is amongus"

  const char kExample4[20] = "red is amongus sus";
  my_strncat(test3, " sus", 5);
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
  assert(my_strlen(test6) == 15);
  assert(test6[14] == '\n');
  assert(test6[15] == '\0');
}

void TestDynamicCopy() {
  char statical[40] = "nwljbknwnkbankn dafn saknwaknDkjkerbknn";

  char* dynamical = my_strdup(statical);

  assert(my_strlen(dynamical) == my_strlen(statical));

  assert(AreStrMatches(statical, dynamical));
  free(dynamical);
}

void TestDynamicLine(){
    FILE* testfile = fopen("test.txt", "r");
    char* line = reinterpret_cast<char*>(calloc(10, sizeof(char)));
    size_t buffer = 10;
    my_getline(&line, &buffer, testfile);

    const char kExample6[16] = "songus amongus\n";
    assert(my_strlen(line) == my_strlen(kExample6));
    assert(AreStrMatches(line, kExample6));

    free(line);
}

void   TestSTRSTR(){
    char example[20] = "qjbejbjEBJVBEWJVNKW";
    char substr[5] = "BJVB";
    char* match = my_strstr(example, substr);
    assert(match != nullptr);
    printf("%d\n", match - example);

}


// strstr
// 
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