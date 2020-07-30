题目：根据一棵树的前序遍历与中序遍历构造二叉树。

解法：前序遍历 [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]   中序遍历 [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]

前+后：
后序遍历中，我们知道 左子树：[post_start,index], 右子树：[index+1, post_end-1]
在前序遍历中，左子树起始位置为pre_start+1,左子树个数一共有(index - post_start)个，因此左子树：[pre_start+1, pre_start+1 + (index - post_start)]
右子树起始位置为左子树终止位置+1，终止位置为pre_end，因此右子树：[ pre_start+1 + (index - post_start) + 1, pre_end]
前+中：
中序遍历中，我们知道 左子树：[inorder_start,index-1], 右子树：[index+1, inorder_end]
在前序遍历中，左子树起始位置为pre_start+1,左子树一共有(index-1 - inorder_start)个，因此左子树：[pre_start+1, pre_start+1 + (index-1 - inorder_start)]
右子树起始位置为左子树终止位置+1，终止位置为pre_end，因此右子树：[ pre_start+1 + (index-1 - inorder_start) + 1, pre_end]
中+后：
中序遍历中，我们知道 左子树：[inorder_start,index-1], 右子树：[index+1, inorder_end]
在后序遍历中，左子树起始位置为post_start，左子树一共有(index-1 - inorder_start)个，因此左子树：[post_start, post_start + (index-1 - inorder_start)]
右子树的终止位置为post_end - 1,右子树一共有(inorder_end - (index+1))个,因此右子树:[post_end - 1 - (inorder_end - (index+1)), post_end - 1]

区分
中、后：
 TreeNode* root=new TreeNode(postorder[postorder_end]);
 int index=inorder_start;
 while(postorder[postorder_end] != inorder[index])
 {
        index++;
 }      
 root->left=dfs(inorder,postorder,inorder_start,index-1,postorder_start,postorder_start+(index-1-inorder_start));
 root->right=dfs(inorder,postorder,index+1,inorder_end,postorder_end-1-(inorder_end-index-1),postorder_end-1);

前、中：
TreeNode* root=new TreeNode(pre[pre_start]);
 int index=inorder_start;
 while(pre[pre_start] != inorder[index])
 {
        index++;
 }      
 root->left=dfs(pre,inorder,pre_start+1,pre_start+1+(index-1-inorder_start),inorder_start,index-1);
 root->right=dfs(pre,inorder,pre_start+1+(index-1-inorder_start)+1,pre_end,index+1,inorder_end);

前、后：
TreeNode* root=new TreeNode(pre[pre_start]);
 int index=postorder_start;
 while(pre[pre_start+1] != postorder[index])
 {
        index++;
 }      
 root->left=dfs(pre,postorder,pre_start+1,pre_start+1+(index-post_start),postorder_start,index);
 root->right=dfs(pre,postorder,pre_start+1,pre_start+1+(index-post_start)+1,pre_end,index+1,post_end-1);



//前、中
class Solution {
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


//中、后
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int inorder_start,int inorder_end,int postorder_start,int postorder_end)
    {
        if(inorder_start > inorder_end || postorder_start > postorder_end)  return NULL;
        TreeNode* root=new TreeNode(postorder[postorder_end]);

        if(postorder_start == postorder_end)    return root;

        int index=inorder_start;
        while(postorder[postorder_end] != inorder[index])
        {
            index++;
        }
        
        root->left=dfs(inorder,postorder,inorder_start,index-1,postorder_start,postorder_start+(index-1-inorder_start));
        root->right=dfs(inorder,postorder,index+1,inorder_end,postorder_end-1-(inorder_end-index-1),postorder_end-1);
        return root;
    }
};
