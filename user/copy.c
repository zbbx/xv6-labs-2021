#include "kernel/types.h"
#include "user/user.h"

// copy.c: copy input to output.

int
main()
{
  char buf[64];

  while(1){
    int n = read(0, buf, sizeof(buf)); // 从标准输入读取到 buf
    if(n <= 0)
      break;
    write(1, buf, n);
  }

  exit(0);
}