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
    TreeNode* firstnode=NULL;
    TreeNode* secnode=NULL;
    TreeNode* prev=NULL;
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        if(prev && !firstnode && prev->val>=root->val){
            firstnode=prev;
        }
        if(firstnode && prev->val>=root->val){
            secnode=root;
        }
        prev=root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp=firstnode->val;
        firstnode->val=secnode->val;
        secnode->val=temp;
    }
};