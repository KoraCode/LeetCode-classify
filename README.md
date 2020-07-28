# LeetCode-classify
用于归类总结其中的一类题型

第一大大类--二叉树
解题密码如下：  
void traverse(TreeNode* root) {  
    // 前序遍历  
    traverse(root->left)  
    // 中序遍历  
    traverse(root->right)  
    // 后序遍历  
}  

1. LeetCode 94 二叉树的中序遍历
2. LeetCode 95 不同的二叉搜索树 II
3. LeetCode 98 验证二叉搜索树
4. LeetCode 99 恢复二叉搜索树
5. LeetCode 100 相同的树
