题目：在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

解法：找规律，以最低行第一个开始，目标比它小就向上-1，比它大就向右+1；越界就是false

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (row >=0 && col < n){
            if(matrix[row][col] < target){
                col += 1;
            }
            else if(matrix[row][col] > target){
                row -= 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
