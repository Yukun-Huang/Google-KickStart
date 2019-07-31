# Google-Kick-Start
这里记录了我的Google Kick Start刷题历程，对于每一道题目我都会做相关的笔记，可以在题目路径下找到。以下是题目的关键词的汇总。

*号表示大数据集尚未解决。

## 2018 Round A
### 1. Even Digits
数字，数位，贪心构造，分析能力
### 2. Lucky Dip
动态规划，二分搜索优化
### 3. Scrambled Words*
字符串问题，频率数组，哈希，复杂度优化

## 2018 Round B
### 1. No Nine
数字，数位，分析能力，找规律
### 2. Sherlock and the Bit Strings*
二进制字符串，动态规划
### 3. King's Circle*
平面几何，二维累积数组

## 2018 Round C
### 1. Planet Distance
图相关，深度优先遍历，广度优先遍历，无向图找环
### 2. Fairies and Witches
回溯法，图相关，平面几何
### 3. Kickstart Alarm
数学相关（等比数列求和，费马小定理），快速幂，大数取模，乘法逆元

## 2018 Round D
### 1. Candies
双指针法，滑动窗口，平衡二叉搜索树，STL multiset
### 2. Paragliding
平面几何，坐标点的排序
### 3. Funniest Word Search*
二维累积数组，最大公约数，子网格遍历

## 2019 Round A
### 1. Training
滑动窗口
### 2. Parcels
二维网格，多源广度优先搜索，二分搜索，曼哈顿距离
### 3. Contention*
待解决

## 2019 Round B
### 1. Building Palindromes
回文，字符出现频率，频率前缀和
### 2. Energy Stones
动态规划，0-1背包问题

## 2019 Round D
### 1. X or What?
异或的性质，STL set

# 经验教训（主要针对c++）

1.在读入数据时如果使用了int类型存储，尽管数据本身没有超范围，但是在进行乘法计算时却可能会产生数值溢出。这在以后必须要考虑到。

2.使用全局定义的数组来存储数据时，要记得在每个case开始时用memset函数初始化一下。否则会产生很隐蔽的bug。

3.函数的局部变量不能定义得过大，否则会导致栈溢出。因为局部变量存在在堆栈空间，其大小一般只有4M或者8M。

