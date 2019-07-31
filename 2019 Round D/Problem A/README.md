### A. X or What?

### 描述

给定N个非负整数和Q个操作，每次操作从中选择一个数并替换为另一个数。问每次操作后所有xor-even子区间的最大长度是多少。

xor-even子区间定义：求该区间内所有整数异或的结果，若该结果有偶数个1，则为xor-even子区间。

### 分析

**异或性质**

性质1

再异或一次等于抵消了异或。例如：A xor B xor C xor C = A xor B

性质2

1.两个xor-even的整型数异或，结果仍然是xor-even;

2.两个xor-odd的整型数异或，结果仍然是xor-even;

3.一个xor-even和一个xor-odd整型数异或，结果是xor-odd.

性质2证明

假设：总位数为w,数一拥有x个0,数二拥有y个0,数一中0匹配了数二中k个1(k<=x)。

因为异或运算产生1只有两种情况：数一的0与数二的1,数一的1与数二的0.

第一种情况1的个数：k.

第二种情况1的个数：数一中0与数二中0匹配的个数为x-k,这不会产生1,这时1的个数应为：y-(x-k)

故1的总个数为：k+y-(x-k)=2*k+y-x

摘自博客：https://blog.csdn.net/zhang_yang_43/article/details/72818933 

**对于小数据集**

1.求异或前缀和O(n),实现O(1)时间的任意区间求异或结果。

2.遍历所有子区间，O(n^2),判断该区间是否为xor-even.找到最大区间长度。

3.对每一个Q都进行相同的处理。

**对于大数据集**

性质2的重要推论

如果某区间内有偶数个xor-odd数，则该区间是xor-even；否则为xor-odd.

解法

1.遍历区间，找出所有xor-odd数的位置，用set存储。

2.对于每一次的修改，更新set，即插入和删除。

3.找最大区间时，如果当前set的size为even，则整个区间构成最大区间。否则，去除左端的xor-odd数或者去除右端的xor-odd数，找到符合的那个最大区间（注意边界情况）。

### 关键词

异或的性质，STL set
