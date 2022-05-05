/* 
为了解决双标志法2中出现的死锁问题
可以引入了一种使得进程在发现其他进程也同样想进入临界区时，
能够回退自己状态的“谦让机制”
 */
int flag[n];
int main()
{
    flag[i] = 1;
    while (flag[j] == 1)
    {
        flag[i] = 0;
        delay;
        flag[i] = 1;
    }
    critical_section;
    flag[i] = 0;
}
/* 算法分析
但是可以考虑这样的情况
P0设置flag[0]为true
P1设置flag[1]为true
P0检查P1
P1检查P0
P0设置flag[0]为false
P1设置flag[1]为false
P0设置flag[0]为true
P1设置flag[1]为true
....
所以程序会以这样的顺序无限循环下去
严格讲，该循环是否产生取决于操作系统给各进程分配的时间片长短
由于循环可能会被程序交替执行的速度所打破，所以可以称作是一个活锁
 */