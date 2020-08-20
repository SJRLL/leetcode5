
给定一个二叉树，原地将它展开为一个单链表。



例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6

//解题思路：
//观察该二叉树与展开链表构造可知：链表元素顺序与先序遍历二叉树顺序一致，且都是由右指针指向后继节点，左指针为null。
//因此，我们可以先序遍历二叉树，让每个元素入队，遍历完成在让节点指向后继，左指针赋空值。

class Solution {
	LinkedList<TreeNode> myList = new LinkedList<>();
	public void flatten(TreeNode root) 
	{
		if (root == null)
			return;
		helper(root);
		TreeNode val = myList.poll();
		while (!myList.isEmpty())
		{
			val.left = null;
			val.right = myList.poll();
			val = val.right;
		}
	}
	private void helper(TreeNode root)
	{
		if (root == null)
			return;
		myList.add(root);
		helper(root.left);
		helper(root.right);
	}
}
