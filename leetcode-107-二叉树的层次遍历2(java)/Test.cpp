给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树[3, 9, 20, null, null, 15, 7],

  3
 / \
9  20
  / \
 15  7
返回其自底向上的层次遍历为：

[
	[15, 7],
	[9, 20],
	[3]
]

//解题思路
//主要就是一点，ArrayList集合的使用，可以使用重载的方式来add，就是每次都添加到集合的索引为0的位置，
//这样就可以反过来进行添加元素了。

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
	public List<List<Integer>> levelOrderBottom(TreeNode root) {

		//使用BFS算法来完成求解
		List<List<Integer>> res = new ArrayList<>();

		//特殊情况判断
		if (root == null){
			return res;
		}

		//创建一个队列
		Queue<TreeNode> que = new LinkedList<>();

		que.offer(root);

		while (que.size() != 0){

			int size = que.size();

			List<Integer> li = new ArrayList<>();

			for (int i = 0; i<size; i++)
			{

				TreeNode cur = que.poll();

				li.add(cur.val);

				if (cur.left != null){

					que.offer(cur.left);
				}

				if (cur.right != null)
				{
					que.offer(cur.right);
				}
			}

			res.add(0, li);

		}

		return res;

	}
}
