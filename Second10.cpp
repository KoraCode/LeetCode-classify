题目：编写一个程序，找出第 n 个丑数。
丑数就是质因数只包含 2, 3, 5 的正整数。

解法：三指针，选最小的前移一步；

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p2,p3,p5;
        p2=p3=p5=0;
        for (int i=1;i<n;++i)
        {
            dp.at(i)=min(min(2*dp[p2],3*dp[p3]),5*dp[5]);
            if (dp[i]==2*dp[p2])
                ++p2;
            if (dp[i]==3*dp[p3])
                ++p3;
            if (dp[i]==5*dp[p5])
                ++p5;
        }
        return dp[n-1];
    }
};
