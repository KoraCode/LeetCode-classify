题目：请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            ++count;
            n=(n-1)&n;    //一个整数减去1，就是把二进制最右边的1变为0；再与原来的整数做位与运算就能把最右边的1变为0；
        }
        return count;
    }
};
