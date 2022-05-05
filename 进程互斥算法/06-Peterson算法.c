/* 
在Dekker算法的基础上，Peterson算法采用了一种更加简单出色的算法
turn的含义就是之前的“谦让”,turn=i就代表进程i可以先进入临界区
因为turn是全局变量，所以turn的值取决于最后一个运行turn=j的进程所覆盖
这就解决了之前产生的活锁问题
 */
int flag[n];
int turn;
void PX()
{
    while (1)
    {
        flag[i] = 1;
        turn = j;
        while (flag[j] && turn == j)
            ;
        critical_section;
        flag[i] = 0;
    }
}
