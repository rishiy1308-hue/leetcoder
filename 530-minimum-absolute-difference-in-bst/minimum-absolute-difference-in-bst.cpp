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
    vector<int> ans;
    void inorder(TreeNode* node){
        if(node == nullptr) return;
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int diff = INT_MAX;
        for(int i = 1;i<ans.size();i++){
            diff = min(diff,abs(ans[i]-ans[i-1]));
        }
        return diff;
    }
};