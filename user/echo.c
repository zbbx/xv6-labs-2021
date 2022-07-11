#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// argc: 参数数量，包括命令名称
// *argv[]: 字符数组，存储命令行参数
int
main(int argc, char *argv[])
{
  int i;

  for(i = 1; i < argc; i++){ // argv[0] 为命令名称，之后为输入参数
    write(1, argv[i], strlen(argv[i]));
    if(i + 1 < argc){
      write(1, " ", 1);
    } else {
      write(1, "\n", 1);
    }
  }
  exit(0);
}
