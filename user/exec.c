#include "kernel/types.h"
#include "user/user.h"

// exec.c: replace a process with an executable file

int
main()
{
  char *argv[] = { "echo", "this", "is", "echo", 0 };

  exec("echo", argv);

  printf("exec failed!\n");

  exit(0);
}