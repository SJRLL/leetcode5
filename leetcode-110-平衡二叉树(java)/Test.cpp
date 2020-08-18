给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树[3, 9, 20, null, null, 15, 7]
  
  3
 / \
9  20
   / \
 15   7
返回 true 。

示例 2:

给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]

  1
 / \
2   2
   / \
  3   3
     / \
    4   4
返回 false 。

//解题思路：
//要判断树是否平衡，就需要保证这棵树的每一个子树都是高度平衡的，如果某一个结点的左右子树高度差大于等于2，那么以这个结点为根的树肯定高度不平衡；
//如果一个结点的左右子树高度小于2Math.abs(height(root.left) - height(root.right)) < 2，
//就需要保证其左右子树都是高度平衡的才能断定这个结点为根的树高度平衡，isBalanced(root.left)为真且isBalanced(root.right)为真才能断定树高度平衡。
//上述思路需要使用辅助函数int height(TreeNode x)来计算树高：如果x == null不存在树，高度为0
//否则以x为根的树高按定义等于左右子树中更高的那棵的高度 + 1return Math.max(height(x.left), height(x.right)) + 1;
//可以看到，对每个节点进行遍历的时候，还需要进行一次递归得到该结点的左右子树，这样的做法其实是两层递归。

public boolean isBalanced(TreeNode root) 
{
	if (root == null) 
		return true;
	if (Math.abs(height(root.left) - height(root.right)) < 2) 
	{
		return isBalanced(root.left) && isBalanced(root.right);
	}
	else return false;
}

private int height(TreeNode x) 
{
	if (x == null) return 0;
	return Math.max(height(x.left), height(x.right)) + 1;
}


