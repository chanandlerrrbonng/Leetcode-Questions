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
    int nodeidx;
    private TreeNode build(int[] preorder, int start, int end){
        if(preorder.length==nodeidx || preorder[nodeidx] < start || preorder[nodeidx]> end) return null;
        int val=preorder[nodeidx++];
        TreeNode root=new TreeNode(val);
        root.left=build(preorder, start, val);
        root.right=build(preorder, val, end);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        if(preorder.length==0) return null;
        nodeidx=0;
        return build(preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}