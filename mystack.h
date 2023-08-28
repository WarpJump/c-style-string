#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define getname "FUNCTION" __FUNCTION__ "CALL CAUSED -> "

#define TRACE                                 \
  const char* funcname = __PRETTY_FUNCTION__; \
  char funcmessage[50] = "FUNCTION ";         \
  strcat(funcmessage, funcname);              \
  strcat(funcmessage, " CALL CAUSED -> ");    \
  AddMessage(backtrace, funcmessage, 50);     \
  for (bool flag__ = true; flag__; BackTracePop(backtrace), flag__ = false)

struct Message {
  char* stringlog;
};

Message* MessageConstruct(char* mess, size_t size);

void MessageDestroy(Message* src);

struct Mystack {
  Message** logs;
  size_t size = 0;
  size_t pointer = 0;
};

Mystack* StackResize(Mystack* src, size_t new_size);

Mystack* Push(Mystack* src, Message mess);

void StackDestroy(Mystack* src);

struct BACKTRACE {
  Mystack* stack;
};

BACKTRACE* BackTraceConstruct();

void BackTraceDestroy(BACKTRACE* src);

BACKTRACE* AddMessage(BACKTRACE* src, const char* str, size_t size);

BACKTRACE* BackTracePop(BACKTRACE* src);

BACKTRACE* PrintTrace(BACKTRACE* src);
