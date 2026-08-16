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
    void inorder(TreeNode* node,int& mini,int level){
        if(node->left == nullptr && node->right == nullptr){
            mini = min(mini,level);
            return ;
        }
        if(node->left) {
            inorder(node->left,mini,level+1);
        }

        if(node->right) inorder(node->right,mini,level+1);

    }
    int minDepth(TreeNode* root) {
        int mini = INT_MAX;
        int level =1;
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        inorder(root,mini,level);
        return mini;
    }
};