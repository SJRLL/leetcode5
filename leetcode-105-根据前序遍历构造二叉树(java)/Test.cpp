根据一棵树的前序遍历与中序遍历构造二叉树。

注意 :
你可以假设树中没有重复的元素。

例如，给出
前序遍历 preorder = [3, 9, 20, 15, 7]
中序遍历 inorder = [9, 3, 15, 20, 7]
返回如下的二叉树：

  3
 / \
 9  20
   / \
  15  7


//解题思路
//构建一个二叉树需要构建三部分：root、左子树、右子树
//左子树、右子树的构建，又包括：root、左子树、右子树
//关键在于定位出根节点，划分出左右子树，然后 递归 构建左右子树

class Solution 
{
	private int in = 0;
	private int pre = 0;
	public TreeNode buildTree(int[] preorder, int[] inorder) 
	{
		return build(preorder, inorder, Integer.MIN_VALUE);
	}
	private TreeNode build(int[] preorder, int[] inorder, int stop) 
	{
		if (pre == preorder.length) return null; // pre走到preorder末尾
		if (inorder[in] == stop) 
		{ // in指针走到了停止点
			in++; // stop点废弃了，in推进一位
			return null;
		}
		TreeNode node = new TreeNode(preorder[pre++]);
		node.left = build(preorder, inorder, node.val);
		// 左子树的停止点是当前的根节点的值
		node.right = build(preorder, inorder, stop);
		// 右子树的停止点是当前树的停止点
		return node;
	}
}
