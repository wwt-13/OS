/* 
设置一个数组flag[n]，当flag[i]=1代表该进程是否处于临界区
此方法是先看排队的双标志法
 */
int flag[n];
int main()
{
    while (flag[j] == 1)
        ;
    flag[i] = 1;
    critical_section;
    flag[i] = 0;
}
/* 算法分析
未满足互斥的要求
p0执行while发现其余均为false
p1执行while发现其余均为false
p0设置flag[0]为true，并进入临界区
p1设置flag[1]为true，并进入临界区

还有这样一种情况
当flag[1]=0时，此时可以进入p0进程，当while语句执行完毕的时候p0进程的时间片用完了
此时中断p0进程的执行，进而开始执行p1进程，巴拉巴拉巴拉巴拉(不满足互斥的基本原则)
 */
