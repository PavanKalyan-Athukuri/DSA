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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = -1;
        while(!queue.isEmpty()){
            int size = queue.size();
            level = level + 1;
            List<Integer> list = new ArrayList<>();
            int odd = Integer.MAX_VALUE;
            int even = Integer.MIN_VALUE;
            boolean isOdd = level%2==1?true:false;
            for(int i=0;i<size;i++){
                TreeNode temp = queue.remove();
                int curr = temp.val;
                if(isOdd){
                    if(curr%2==1||curr>=odd)
                        return false;
                    odd = curr;
                }
                else{
                    if(curr%2==0||curr<=even)
                        return false;
                    even = curr;
                }
                if(temp.left!=null)
                    queue.add(temp.left);
                if(temp.right!=null)
                    queue.add(temp.right);
            }
        }
        return true;
    }
}