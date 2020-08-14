题目：给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？

//动态规划 ans=max(ans,dp[i]*dp[n-i])
class Solution {
    int dp(int n){
        if(n <= 4) return n;
        int ans = n;
        for(int i = 1; i <= n/2; i ++){
            ans = max(ans, dp(n - i)*dp(i));
        }
        return ans;
    }
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        return dp(n); 
    }
};

//贪婪算法
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 2) return 0;
        if(n == 3 || n ==2 )  return n-1;
        
        int num3=n/3;
        if(n-num3*3 == 1)   --num3;
        int num2=(n-num3*3)/2;
        int ans=pow(3,num3)*pow(2,num2);
        return ans;
    }
};
