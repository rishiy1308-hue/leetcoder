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
    int sum = 0;
     int cnt = 0;

    void inorder(TreeNode* root, int& sum,int& cnt){
        if(root == nullptr) return;
        inorder(root->left,sum,cnt);
        sum+=root->val;
        cnt = cnt+1;
        inorder(root->right,sum,cnt);
        return;
    }
    void average(TreeNode* root,int& cnt1){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            cnt1++;
            return;
        }
        inorder(root,sum,cnt);
        if(root->val == sum/cnt) cnt1++;
        sum = 0;
        cnt = 0;
        average(root->left,cnt1);
        average(root->right,cnt1);
    }
    
    int averageOfSubtree(TreeNode* root) {
        int cnt1 = 0;
        average(root,cnt1);
        return cnt1;
    }
};