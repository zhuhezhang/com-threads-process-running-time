//该程序利用2个进程统计从1加到1亿所需时间

#include "apue.h"
#include <time.h>

int main()
{
    int fd[2];
    pid_t pid;
  
    if(pipe(fd) < 0)
        err_sys("pipe error");
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)//进程1
    {
       char result[20];
       unsigned long long int result1 = 0;
       for(int i = 1; i <= 50000000; i++)
          result1 += i;
       printf("进程1结果：%llu\n",result1);
       sprintf(result,"%lld",result1);
       close(fd[0]);
       write(fd[1],result,sizeof(result));
    }
    else            //进程2
    {
       char result[20];
       unsigned long long int result1 = 0;
       for(int i = 50000001; i <= 100000000; i++)
          result1 += i;
       printf("进程2结果：%llu\n",result1);
       close(fd[1]);
       read(fd[0],result,sizeof(result));
       result1 += strtoull(result,NULL,0);
       printf("最后结果：%llu\n",result1);
       printf("程序运行时间：%fs\n",(double)clock()/CLOCKS_PER_SEC);
    }
}
