题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

解法：[状态] 到达n阶；[选择]选一次爬1阶还是2阶；状态转移方程 f(x)=f(x-1)+f(x-2);
然后再考虑边界问题：f(0)=1,f(1)=1

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
