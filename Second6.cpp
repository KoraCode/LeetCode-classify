题目：给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

解法：[状态]是 最后的阶梯；[选择] 是 阶梯上一层还是上一层-1结点； 
边界划分：f[0][0]=triangle[0][0];
          当j=0时，只有上面的结点： f[i][0]=f[i-1][0]+triangle[i][0];
          当j=i时，只有上面的结点-1： f[i][i]=f[i-1][i-1]+triangle[i][i];
          其他就是： f[i][j]=min(f[i-1][j-1],f[i-1][j]) + triangle[i][j];

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};
