题目：给定一个二叉树，判断它是否是高度平衡的二叉树。

解法：根据节点的左右子树的深度来判断

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int d = abs(depth(root->left)-depth(root->right)); //当前节点的左右子树的高度差
        
        return (d<=1) && (isBalanced(root->left)) && (isBalanced(root->right));
    }
    
    // 求解二叉树深度（104题）
    int depth(TreeNode* node)
    {
        if(node ==NULL) return 0;
        return max( depth(node->left), depth(node->right) )+1;
    }
    
};
