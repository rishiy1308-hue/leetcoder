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
    void inorder(TreeNode* node, int& sum) {
        if (node == nullptr) return;

        if (node->left) {
            if (node->left->left == nullptr &&
                node->left->right == nullptr) {
                sum += node->left->val;
            }

            inorder(node->left, sum);
        }

        if (node->right) {
            inorder(node->right, sum);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return sum;
    }
};