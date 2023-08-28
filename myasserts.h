/*!
\file
\brief File with defines of custom asserts and defines of tests
*/

#include "colors.h"

#ifndef NDEBUG
#define errfile debugfile
#else
#define errfile stderr
#endif

#define printerror(file, message)                           \
  fprintf(file, message " in function \"%s\" in line %d\n", \
          __PRETTY_FUNCTION__, __LINE__)

#define logfatal(error)                                              \
  printerror(errfile, RedText("!FATAL ERROR! ") MagentaText(error)); \
  fclose(errfile)

#define printfatal(error) \
  printerror(stderr, RedText("!FATAL ERROR! ") MagentaText(error));

#define printnonfatal(error) \
  printerror(stderr, OrangeText("*NONFATAL ERROR* ") MagentaText(error))

#define lognonfatal(error) \
  printerror(errfile, OrangeText("*NONFATAL ERROR* ") MagentaText(error))

#define logwarning(error) \
  printerror(errfile, BlueText(".WARNING. ") MagentaText(error));

#define printwarning(error) \
  printerror(stderr, BlueText(".WARNING. ") MagentaText(error));

#define TRASE_RET(value)    \
  BackTracePop(backtrace); \
  return value

/*!
\brief Exception controlling block.
\param statement - boolian expression. If not true throws an error
*/

// some assert defines for degubbing
/////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG
#define AssertError(statement, error_code)                 \
  do {                                                     \
    if (!(statement)) {                                    \
      fprintf(stderr, "Error in function %s in line %d\n", \
              __PRETTY_FUNCTION__, __LINE__);              \
      return error_code;                                   \
    }                                                      \
  } while (0)
#else
#define AssertError(...) \
  do {                   \
  } while (0)
#endif

////////////////////////////////////////////////////////////////////////////

/*!
\brief primary functions where statements can be used, stores number of corrrect
test \param test_case_name - group of test name \param test_name - name of test
*/

#define TEST(test_case_name, test_name)                                  \
  int true_test = 0;                                                     \
  int* test_param_name = &true_test;                                     \
  for (int one_iteration__ = 0; one_iteration__ != 1; ++one_iteration__, \
           printf(GreenText("CORRECT TESTS") " %d\n", true_test))

// asserts defined for testing or as checks for real mode

#ifndef NDEBUG
#define ASSERT_POINTERS_NOT_EQUAL(ptr_1, ptr_2, value)                       \
  do {                                                                       \
    if (ptr_1 == ptr_2) {                                                    \
      printfatal("ASSERTION FAILED: EQUAL POINTERS TO DIFFERENT VARIABLES"); \
      return value;                                                          \
    }                                                                        \
  } while (0)
#else
#define ASSERT_POINTERS_NOT_EQUAL(...)
#endif

#define nullpointer "ASSERTION FAILED: NULL POINTER"
#ifndef NDEBUG
#define ASSERT_POINTER_NOT_NULL(ptr, value)   \
  do {                                        \
    if (ptr == nullptr) {                     \
      printnonfatal(nullpointer);             \
      lognonfatal(nullpointer);               \
      AddMessage(backtrace, nullpointer, 31); \
      PrintTrace(backtrace);                  \
      BackTracePop(backtrace);\
      TRASE_RET(value);                        \
    }                                         \
  } while (0)
#else
#define ASSERT_POINTER_NOT_NULL(...)
#endif

#ifndef NDEBUG
#define ASSERT_ALLOCALION_SIZE_NOT_ZERO(size, value)                    \
  do {                                                                  \
    if (size == 0) {                                                    \
      printnonfatal("ASSERTION FAILED: ALLOCATION SIZE IS ZERO BYTES"); \
      logfatal("ASSERTION FAILED: ALLOCATION SIZE IS ZERO BYTES");      \
      return value;                                                     \
    }                                                                   \
  } while (0)
#else
#define ASSERT_ALLOCALION_SIZE_NOT_ZERO(...)
#endif

#define ASSERT_EQ(first, second)                  \
  do {                                            \
    if (first != second) {                        \
      printnonfatal("EQUATION ASSERTION FAILED"); \
      printf("%d != %d \n\n\n", first, second);   \
      break;                                      \
    }                                             \
    (*test_param_name)++;                         \
  } while (0)

#define ASSERT_TRUE(statement)                   \
  do {                                           \
    if (!(statement)) {                          \
      printnonfatal("BOOLEAN ASSERTION FAILED"); \
      break;                                     \
    }                                            \
    (*test_param_name)++;                        \
  } while (0)

#define ASSERT_DOUBLE_EQ(double_1, double_2)             \
  do {                                                   \
    if (!CompareDoubles(double_1, double_2)) {           \
      printnonfatal("DOUBLE EQUATION ASSERTION FAILED"); \
      break;                                             \
    }                                                    \
    (*test_param_name)++;                                \
  } while (0)
