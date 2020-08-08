题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
      如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
      
解法：回溯法，先遍历矩阵找到第一个字母的位置，再进行递归回溯找字母上下左右的字母是否匹配对应的word位置；

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if (dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i,int j,int length){
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||length>=word.size()||word[length]!=board[i][j]){
            return false;
        }
        if(length==word.size()-1&&word[length]==board[i][j]){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='0';
        bool flag=dfs(board,word,i,j+1,length+1)||dfs(board,word,i,j-1,length+1)||dfs(board,word,i+1,j,length+1)||dfs(board,word,i-1,j,length+1);
        board[i][j]=temp;
        return flag;
    }
};
