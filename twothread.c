//该程序利用1个进程的2个线程统计从1加到1亿所需时间

#include "apue.h"
#include <time.h>
#include <pthread.h>

void *thread2(void *result2)
{
    unsigned long long int *result3 = (unsigned long long int *)result2;
    for(int i = 50000001; i <= 100000000; i++)
       *result3 += i;
    printf("线程2结果：%llu\n",*result3);
}

int main()
{
    pthread_t ntid;
    unsigned long long int result1 = 0,result2 = 0;

    pthread_create(&ntid,NULL,thread2,&result2);
    for(int i = 1; i <= 50000000; i++)
       result1 += i;
    printf("线程1结果：%llu\n",result1);
    printf("最后结果：%llu\n",result1 + result2);
    printf("程序运行时间：%fs\n",(double)clock()/CLOCKS_PER_SEC);
}
