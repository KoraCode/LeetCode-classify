# LeetCode-classify
用于归类总结其中的一类题型

第一大类--二叉树  
解题密码如下：  
void traverse(TreeNode* root) {  
    // 前序遍历  
    traverse(root->left)  
    // 中序遍历  
    traverse(root->right)  
    // 后序遍历  
}  

1.  LeetCode 94  二叉树的中序遍历
2.  LeetCode 95  不同的二叉搜索树 II
3.  LeetCode 98  验证二叉搜索树
4.  LeetCode 99  恢复二叉搜索树
5.  LeetCode 100 相同的树
6.  LeetCode 101 对称二叉树
7.  LeetCode 102 二叉树的层序遍历
8.  LeetCode 103 二叉树的锯齿形层序遍历
9.  LeetCode 104 二叉树的最大深度
10. LeetCode 105 从前序与中序遍历序列构造二叉树（前、后 和 中、后遍历）
11. LeetCode 108 将有序数组转换为平衡二叉树
12. LeetCode 110 判断是否为平衡二叉树
13. LeetCode 111 二叉树的最小深度
14. LeetCode 112 路径总和
15. LeetCode 113 路径总和II
16. LeetCode 114 二叉树展开为链表
17. LeetCode 116 填充每一个节点的下一个右侧节点指针
18. LeetCode 129 求根到叶子节点数字之和
19. LeetCode 199 二叉树的右视图


第二大类--动态规划
解题密码：
(1)重叠子问题;  
(2)最优子结构;  
(3)状态转移方程;(明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义)  
确定「状态」，也就是原问题和子问题中会变化的变量。  
确定「选择」，也就是导致「状态」产生变化的行为。  

1. LeetCode 53 最大子序和
2. LeetCode 62、63 不同路径
3. LeetCode 64 最小路径和
4. LeetCode 70 爬楼梯
5. LeetCode 91 解码方法
