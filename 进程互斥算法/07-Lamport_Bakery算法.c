/* 
面包店算法的基本思想来源于顾客在面包店购买面包时的排队原理
1. 顾客进入面包店，首先抓取一个号码，然后按照号码从小到大的次序依次进入面包店购买面包
2. 面包店按照从小到大的次序发放号码，且多个客户可能得到相同的号码(可以通过互斥机制解决)
3. 如果多个顾客抓到了相同的号码，则按照顾客名字典序获取面包
 */
#define n 100
#define false 0
#define true 1
int Choosing[n]; // 表示进程i是否在抓号
int Number[n];   // 记录进程i抓到的号码
void ENTRY_SECTION(int i)
{
    while (true)
    {
        Choosing[i] = true;
        Number[i] = 1 + max(Number[0->n]);
        Choosing[i] = false;
        for (int j = 1; j < n; j++)
        {
            // 此处的两个while都是忙等
            while (Choosing[j] != false)
                ;   // 等待进程j分配到自己的number
                    // 此处等待的原因(估计还是并发引发的问题)
            while (Number[i] != 0 && (Number[j], j) < (Number[i], i))
                ; // 等待具备更高优先级的进程完成它们的工作
        }
        critical_section;
        Number[i] = 0;
    }
}