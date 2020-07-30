题目：给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

方法一：递归，可分四种情况：
1.根节点没有左右子树,返回1,此时left = 0, rigeht = 0, return left + right + 1成立
2.根节点没有右子树,left + 1,此时right = 0,return left + right + 1成立
3.根节点没有左子树,right + 1,此时left = 0,return left + right + 1成立
4.根节点存在左右子树,返回根节点到左右子树的最小值 + 1,return min(left,right) + 1


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;  //递归结束
        int left = minDepth(root->left);  //计算左子树的高度
        int right = minDepth(root->right);  //计算右子树的高度
        if (!left || !right) return left + right + 1;  //如果有一个空，则+1
        return min(left, right) + 1;  //否则最小值+1
    }
};
