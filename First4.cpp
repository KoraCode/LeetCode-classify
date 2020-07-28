题目：二叉搜索树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

解法：中序遍历后sort重排序数组，再进行比较修改二叉搜索树

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> result;
        inOrder(root,result);
        sort(result.begin(),result.end());
        recover(root,result);
    }

    void inOrder(TreeNode* root,vector<int>& vecResult){
        if(root == nullptr){
            return;
        }
        inOrder(root->left,vecResult);
        vecResult.push_back(root->val);
        inOrder(root->right,vecResult);
    }

    void recover(TreeNode* root,vector<int>& rec){
        if(root ==nullptr){
            return;
        }
        recover(root->left,rec);
        if(root->val == rec[0]){
            rec.erase(rec.begin());
        }else{
            root->val = rec[0];
            rec.erase(rec.begin());
        };
        recover(root->right,rec);
    }
};
