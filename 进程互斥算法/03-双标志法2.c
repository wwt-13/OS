/* 
同样是双标志法，只不过此时先抢位置
 */
int flag[n];
int main()
{
    flag[i] = 1;
    while (flag[j] == 1)
        ;
    critical_section;
    flag[i] = 0;
}
/* 算法分析
满足了互斥的情况，但是可能出现死锁
也就是说同时置位后都停止在了while处死循环
 */