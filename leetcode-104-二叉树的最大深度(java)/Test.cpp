给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明 : 叶子节点是指没有子节点的节点。

示例：
给定二叉树[3, 9, 20, null, null, 15, 7]，

    3
   / \
   9  20
	  / \
	 15  7

//解题思路
//递归DFS和BFS实现。
//DFS就递归每一个结点，如果为空就返回0，否则就返回左右子树高度更大者的数值加本层的1,BFS类似按层输出二叉树的每层结点，记录多少层。

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
	//递归，类似DFS
	public int maxDepth(TreeNode root) {//递归每一个结点，如果为空就返回0，否则就返回左右子树高度更大者的数值加本层的1
		return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
	}
	//BFS
	public int maxDepth(TreeNode root) 
	{
		if (root == null) return 0;
		Queue<TreeNode> queue = new LinkedList<>();//使用队列实现BFS
		int height = 0;
		queue.offer(root);
		while (!queue.isEmpty())
		{
			int size = queue.size();//使用一个计数器实现类似按层输出的情景
			while (size > 0)
			{
				TreeNode curNode = queue.remove();
				if (curNode.left != null) queue.offer(curNode.left);
				if (curNode.right != null) queue.offer(curNode.right);
				size--;
			}
			height++;
		}
		return height;
	}
}
