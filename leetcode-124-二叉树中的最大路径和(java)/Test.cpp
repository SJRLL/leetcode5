
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入 : [1, 2, 3]

	 1
	/ \
	2   3

输出: 6

示例 2 :

输入 : [-10, 9, 20, null, null, 15, 7]

	 - 10
	 / \
	 9  20
	   / \
	  15   7

 输出: 42

//方法一：递归
//解题思路：
//(1) 从根节点开始递归计算经过每个节点的最大路径和。
//(2) 递归完成返回整个二叉树的最大路径和。

/**
* Definition for a binary tree node.
* public class TreeNode {
*     int val;
*     TreeNode left;
*     TreeNode right;
*     TreeNode(int x) { val = x; }
* }
*/
class Solution {
		 int maxSum = Integer.MIN_VALUE;

		 public int maxPathSum(TreeNode root) 
		 {
			 // 从根节点开始递归计算。
			 maxGain(root);
			 return maxSum;
		 }

		 public int maxGain(TreeNode node) 
		 {
			 if (node == null) 
			 {
				 return 0;
			 }

			 // 只有左右子节点的最大贡献值大于 0 ，当前节点的最大贡献值才会变大。
			 int leftGain = Math.max(maxGain(node.left), 0);
			 int rightGain = Math.max(maxGain(node.right), 0);

			 // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值。
			 int priceNewpath = node.val + leftGain + rightGain;

			 // 更新最大和记录。
			 maxSum = Math.max(maxSum, priceNewpath);

			 // 返回当前节点的最大贡献值。
			 return node.val + Math.max(leftGain, rightGain);
		 }
}
