//该程序利用4个进程统计从1加到1亿所需时间

#include "apue.h"
#include <time.h>

int main()
{
    int fd1[2];
    pid_t pid1;
    if(pipe(fd1) < 0)
       err_sys("pipe error");

    if((pid1 = fork()) < 0)
       err_sys("fork error");
    else if(pid1 == 0)
    {
       int fd2[2];
       pid_t pid2;
       if(pipe(fd2) < 0)
          err_sys("pipe error");

       if((pid2 = fork()) < 0)
          err_sys("fork error");
       else if(pid2 == 0)
       {
          int fd3[2];
          pid_t pid3;
          if(pipe(fd3) < 0)
             err_sys("pipe error");

          if((pid3 = fork()) < 0)
             err_sys("fork error");
          else if(pid3 == 0)//进程4
          {
             char result[20];
             unsigned long long int result1 = 0;
             for(int i = 1; i <= 25000000; i++)
                result1 += i;
             printf("进程4结果：%llu\n",result1);
             sprintf(result,"%lld",result1);
             close(fd3[0]);
             write(fd3[1],result,sizeof(result));
          }
          else             //进程3
          {
             char result[20];
             unsigned long long int result1 = 0;
             for(int i = 25000001; i <= 50000000; i++)
                result1 += i;
             printf("进程3结果：%llu\n",result1);
             close(fd3[1]);
             read(fd3[0],result,sizeof(result));
             result1 += strtoull(result,NULL,0);
             sprintf(result,"%lld",result1);
             close(fd2[0]);
             write(fd2[1],result,sizeof(result));
          }
       }
       else                //进程2
       {
          char result[20];
          unsigned long long int result1 = 0;
          for(int i = 50000001; i <= 75000000; i++)
             result1 += i;
          printf("进程2结果：%llu\n",result1);
          close(fd2[1]);
          read(fd2[0],result,sizeof(result));
          result1 += strtoull(result,NULL,0);
          sprintf(result,"%lld",result1);
          close(fd1[0]);
          write(fd1[1],result,sizeof(result));
       }
    }
    else                   //进程1
    {
       char result[20];
       unsigned long long int result1 = 0;
       for(int i = 75000001; i <= 100000000; i++)
          result1 += i;
       printf("进程1结果：%llu\n",result1);
       close(fd1[1]);
       read(fd1[0],result,sizeof(result));
       result1 += strtoull(result,NULL,0);
       printf("最后结果：%llu\n",result1);
       printf("程序运行时间：%fs\n",(double)clock()/CLOCKS_PER_SEC);
    }
}
