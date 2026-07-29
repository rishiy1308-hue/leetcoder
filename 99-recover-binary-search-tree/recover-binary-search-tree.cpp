/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node,vector<TreeNode*>& ans){
        if(node==nullptr) return;
        inorder(node->left,ans);
        ans.push_back(node);
        inorder(node->right,ans);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans;
        inorder(root,ans);
        int first=-1,middle=-1,last=-1;
        for(int i=1;i<ans.size();i++){
            if((ans[i]->val<ans[i-1]->val) && first==-1){
                first=i-1;
                middle=i;
            }
            else if(ans[i]->val<ans[(i-1)]->val) last=i;
        }
        if(last!=-1){
            swap(ans[first]->val,ans[last]->val);
        }
        else{
            swap(ans[first]->val,ans[middle]->val);
        }
        return;
    }
};