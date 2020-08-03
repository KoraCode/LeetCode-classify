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
