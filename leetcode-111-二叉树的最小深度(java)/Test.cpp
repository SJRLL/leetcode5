给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明 : 叶子节点是指没有子节点的节点。

 示例 :

给定二叉树 [3, 9, 20, null, null, 15, 7],

  3
 / \
9  20
   / \
  15  7
返回它的最小深度  2.


//解题思路
//本题是 104 题求最大深度的相反题目,相比之下除了递归求解左右子树的深度外，还需要考虑左右子树是否为空这个情况
//如果有为空的情况，则直接返回两者深度之和再加上根节点的 1
//若都不为空，则求两者最小深度再加上根节点即可。

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
	public int minDepth(TreeNode root) 
	{
		if (root == null) 
		{
			return 0;
		}
		// 左右子树分别递归求各自的深度
		int left = minDepth(root.left);
		int right = minDepth(root.right);
		// 如果左右子树都为空或者有一方为空，则直接返回两者的深度 + 1即可
		if (root.left == null || root.right == null) 
		{
			return left + right + 1;
		}
		// 若都不为空就选两者最小的深度 + 1 
		return Math.min(left, right) + 1;
	}
}
