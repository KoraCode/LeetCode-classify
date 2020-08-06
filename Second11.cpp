题目：给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

解法：

class Solution {
public:
    int numSquares(int n) {
        vector<int> result(n+1,INT_MAX); // 每个数的最优解都存在result数组里
        result[0] = 0;
        for (int i = 1; i <= n; i++){
            for(int j = 1; i-j*j >= 0 ; j++) {  // 观察比N小的数，且符合N = IxI + N'的数值
                result[i] = min(result[i], result[i-j*j] + 1); // 把最优解（最小值）+ 1 写入result
            }
        }
        return result[n];
    }
};
