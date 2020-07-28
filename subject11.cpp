给定一个二叉树，返回它的中序 遍历。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //递归的常用模板
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
		    if (!root) return ret;    //边界判断
		    mid_order(root, ret);     //用递归进行中序遍历
		    return ret;
    }
    
    void mid_order(TreeNode* root,vector<int>& ret)
    {
        if(root == NULL)
        {
            return;
        }
        mid_order(root->left, ret);
		    ret.push_back(root->val);         //使用中序遍历
		    mid_order(root->right, ret);
    }
};
