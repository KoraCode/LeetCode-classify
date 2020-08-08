题目：地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？

解法：回溯法

class Solution {
public:
    int get(int x) {
        int res=0;
        while(x > 0){
            res += x % 10;
            x/=10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int>> tmp(m,vector<int>(n,0));
        return dfs(m,n,k,0,0,tmp);
    }

    int dfs(int m, int n, int k,int row,int col,vector<vector<int>>& tmp)
    {
        int count=0;
        if(row>=0&&row<m&&col>=0&&col<n&&!tmp[row][col]&&get(row)+get(col)<=k)    
        {
            tmp[row][col]=1;
            count=1+dfs(m,n,k,row,col-1,tmp)
                   +dfs(m,n,k,row,col+1,tmp)
                   +dfs(m,n,k,row-1,col,tmp)
                   +dfs(m,n,k,row+1,col,tmp);
        }
        return count;
    }
};
