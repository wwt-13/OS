/* 
算法四的进程满足了互斥，解决了死锁问题，留有一个互相谦让的活锁
我们可以借鉴算法一的思想，通过一个全局变量turn来指定一个进程进入临界区，这样既可满足所以要求
 */
int flag[n];
int turn;
void PX()
{
    while (1)
    {
        flag[x] = 1;
        while (flag[other])
        {
            if (turn == 1)
            {
                flag[x] = 0;
                while (turn == 1)
                    ;
                flag[x] = 1;
            }
        }
        cirtical_section;
        turn = 0;
        flag[x] = 0;
    }
}
/* 算法分析
在其他进程进入临界区的时候
同样会出现忙等的现象
 */