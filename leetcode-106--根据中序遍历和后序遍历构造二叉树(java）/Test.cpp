根据一棵树的中序遍历与后序遍历构造二叉树。

注意 :
你可以假设树中没有重复的元素。

例如，给出
中序遍历 inorder = [9, 3, 15, 20, 7]
后序遍历 postorder = [9, 15, 7, 20, 3]
返回如下的二叉树：

  3
 / \
9  20
   / \
  15  7


//解题思路
//中序可以和前序、后序、层序的任意一个搭配来构建唯一的二叉树。
//若没有中序，其他的序列搭配都无法构建唯一的二叉树，因为先序、后序、层序都用于提供根结点，只有中序才能区分左右子树。

class Solution {
	private int[] post; //后序序列
	private Map<Integer, Integer> map; //哈希表记录结点值在中序里的下标

	public TreeNode buildTree(int[] inorder, int[] postorder) 
	{
		post = postorder;
		map = new HashMap<>();
		for (int i = 0; i < inorder.length; i++)
			map.put(inorder[i], i);
		return helper(0, inorder.length - 1, post.length - 1);
	}

	/**
	* 根据中序始末下标构建树
	* @param begin 中序的起始下标
	* @param end 中序的结束下标
	* @param postidx 根结点在后序里的下标
	* @return 返回树的根结点
	*/
	private TreeNode helper(int begin, int end, int postidx) 
	{
		if (begin > end)    return null; //没有结点，返回空树
		int rootidx = map.get(post[postidx]); //根结点在中序里的下标，用于区分左右子树
		TreeNode root = new TreeNode(post[postidx]);
		int rightcnt = end - rootidx; //右子树结点数
		root.left = helper(begin, rootidx - 1, postidx - rightcnt - 1); //根据子树的中序构建子树
		root.right = helper(rootidx + 1, end, postidx - 1);
		return root;
	}
}

