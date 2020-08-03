题目：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

解法：创建二维数组dp，与原始网格的大小相同，{dp}[i][j]dp[i][j] 表示从左上角出发到 (i,j)(i,j) 位置的最小路径和。显然，
dp[0][0]=grid[0][0]。对于dp 中的其余元素，通过以下状态转移方程计算元素值。

当 i>0 且 j=0 时，{dp}[i][0]=dp[i−1][0]+grid[i][0]。
当 i=0 且 j>0 时，{dp}[0][j]=dp[0][j−1]+grid[0][j]。
当 i>0 且 j>0 时，{dp}[i][j]=min(dp[i−1][j],dp[i][j−1])+grid[i][j]。

最后得到 \textit{dp}[m-1][n-1]dp[m−1][n−1] 的值即为从网格左上角到网格右下角的最小路径和。

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};
