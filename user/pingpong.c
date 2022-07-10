#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*

*/
int main() {
    int p[2];
    char buf[8];

    pipe(p); // 初始化管道

    int pid = fork(); // 新启动进程
    // fprintf(1, "[debug]pid value is %d\n", pid); // 父子进程同时输出结果：[[ddebebuugg]]pipdi d vvaalluuee  iis s 0

    if (pid < 0){
        printf("error: fork failed\n");
        exit(0);
    } else if (pid == 0) {
        // printf("[debug]pid value is %d\n", pid);

        read(p[0], buf, sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
        write(p[1], "pong", 5);
        close(p[0]);
        close(p[1]);
    } else {
        write(p[1], "ping", 5);
        int eStatus; // 记录 child 进程退出状态
        wait(&eStatus); // 等待 child 进程退出
        // printf("[debug]pid value is %d\n", pid);
        // printf("[debug]child exit %d\n", eStatus);

        read(p[0], buf, sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
        close(p[0]);
        close(p[1]);
    }
    exit(0);
}