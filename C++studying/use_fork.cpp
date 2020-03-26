#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    pid_t pid;
    signal(SIGCHLD, SIG_IGN);
    printf("before fork pid:%d\n", getpid());
    int abc = 10;
    pid = fork();
    if (pid == -1) 
    {           //错误返回
        perror("tile");
        return -1;
    }
    if (pid > 0) 
    {              //父进程空间

        abc++;
        printf("parent:pid:%d \n", getpid());
        printf("abc:%d \n", abc);
        sleep(20);
    }
    else if (pid == 0) 
    {       //子进程空间

        abc++;
        printf("child:%d,parent: %d\n", getpid(), getppid());
        printf("abc:%d", abc);
    }
    printf("fork after...\n");
 }