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
    void inorder(TreeNode* node, map<int,int>& mpp){
        if(node == nullptr) return ;
        inorder(node->left,mpp);
        mpp[node->val]++;
        inorder(node->right,mpp);
        return ;
    }

    vector<int> findMode(TreeNode* root) {
        map<int,int> mpp;
        inorder(root,mpp);
        int maxi = INT_MIN;
        for(auto it:mpp){
            maxi = max(maxi,it.second);
        }
        vector<int> cnt;
        for(auto it:mpp){
            if(it.second == maxi){
                cnt.push_back(it.first);
            }
        }
        return cnt;
    }
};