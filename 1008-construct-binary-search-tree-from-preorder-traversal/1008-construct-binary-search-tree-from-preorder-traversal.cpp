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
    TreeNode* build(deque<int>& p, vector<int> &i){
        if(i.empty()) return NULL;
        int val=p.front();
        p.pop_front();
        auto it=find(i.begin(), i.end(), val);
        int idx=it-i.begin();
        vector<int>left(i.begin(), i.begin()+idx);
        vector<int>right(i.begin()+idx+1, i.end());
        TreeNode* root=new TreeNode(val);
        root->left=build(p, left);
        root->right=build(p, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(), preorder.end());
        deque<int>dq(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        
        TreeNode* head=build(dq, inorder);
        return head;
        
    }
};