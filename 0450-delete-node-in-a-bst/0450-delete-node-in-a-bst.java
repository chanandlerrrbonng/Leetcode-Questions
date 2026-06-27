/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int findmin(TreeNode root){
        if(root.left==null) return root.val;
        else return findmin(root.left);
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null) return null;
        else if(root.val>key) root.left=deleteNode(root.left, key);
        else if(root.val<key) root.right=deleteNode(root.right, key);
        else{
            if(root.right==null && root.left==null) return null;
            else if((root.right==null && root.left!=null) || (root.right!=null && root.left==null)){
                return root.left !=null ? root.left : root.right;
            }
            else{
                root.val=findmin(root.right);
                root.right=deleteNode(root.right, root.val);
            }
        }
        return root;
    }
}