题目：给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

解法：判断树的深度为复数还是单数，单数使用insert添加数据

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(ans,root,0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans,TreeNode* root,int level)
    {
        if(!root)   return;
        if(level >= ans.size())
        {
            ans.push_back(vector<int>());
        }
        if(level%2 == 0)
        {
            ans[level].push_back(root->val);
        }
        else
        {
            ans[level].insert(ans[level].begin(),root->val);
        }

        dfs(ans,root->left,level+1);
        dfs(ans,root->right,level+1);

    }
};
