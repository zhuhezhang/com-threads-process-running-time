//该程序利用1个进程的4个线程统计从1加到1亿所需时间

#include "apue.h"
#include <time.h>
#include <pthread.h>

void *thread2(void *result2)
{
    unsigned long long int *result3 = (unsigned long long int *)result2;
    for(int i = 1; i <= 25000000; i++)
       *result3 += i;
    printf("线程2结果：%llu\n",*result3);
}

void *thread3(void *result3)
{
    unsigned long long int *result4 = (unsigned long long int *)result3;
    for(int i = 25000001; i <= 50000000; i++)
       *result4 += i;
    printf("线程3结果：%llu\n",*result4);
}

void *thread4(void *result4)
{
    unsigned long long int *result5 = (unsigned long long int *)result4;
    for(int i = 50000001; i <= 75000000; i++)
       *result5 += i;
    printf("线程4结果：%llu\n",*result5);
}

int main()
{
    pthread_t ntid2,ntid3,ntid4;
    unsigned long long int result1 = 0,result2 = 0,result3 = 0,result4 = 0;

    pthread_create(&ntid2,NULL,thread2,&result2);
    pthread_create(&ntid3,NULL,thread3,&result3);
    pthread_create(&ntid4,NULL,thread4,&result4);
    
    for(int i = 75000001; i <= 100000000; i++)
       result1 += i;
    printf("线程1结果：%llu\n",result1);
    printf("最后结果：%llu\n",result1 + result2 + result3 +result4);
    printf("程序运行时间：%fs\n",(double)clock()/CLOCKS_PER_SEC);
}
