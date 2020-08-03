题目：一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？


解法：[状态] 就是 下和右；[选择] 就是 向下和向右; dp数组是 dp[i][j]=dp[i-1][j]+dp[i][j-1]; 边界i=0和j=0时，dp[i][j]=0;

class Solution {
public:
    int uniquePaths(int m, int n) {
	    vector<vector<int>>G(m,vector<int>(n,0));
	    for (int i = 0; i < m; i++)
            {
		    for (int j = 0; j < n; j++)
		    {
			if (!i && !j)
			{
			    G[i][j] = 1;
			    continue;
		    	}
		    	if (i == 0)
			{
			    G[i][j] = G[i][j - 1];
			    continue;
		    	}
		    	if (j == 0)
		    	{
			    G[i][j] = G[i - 1][j];
			    continue;
		        }
		    	G[i][j] = G[i][j - 1] + G[i - 1][j];
	    	    }
            }
	    return G[m - 1][n - 1];
    }   
};

题目：现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

解法：多了一个判断是否有障碍物，如果有则G[0]=0；运用「滚动数组思想」把空间复杂度优化称 O(m)O(m)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return false;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int table[101] = {0};
        table[1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i-1][j-1] == 0) 
                    table[j] += table[j-1];
                else 
                    table[j] = 0; 
            }
        }
        return table[n];
    }
};
