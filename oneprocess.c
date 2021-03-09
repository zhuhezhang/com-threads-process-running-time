//该程序利用1个进程统计从1加到1亿所需时间

#include "apue.h"
#include <time.h>

int main()
{
    unsigned long long int result = 0;
    for(int i = 1; i <= 100000000; i++)
    {
        result += i;
    }
    printf("计算结果：%llu\n",result);
    printf("程序运行时间：%fs\n",(double)clock()/CLOCKS_PER_SEC);
}
