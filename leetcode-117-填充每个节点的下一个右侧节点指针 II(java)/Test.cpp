给定一个二叉树

struct Node {
	int val;
	Node *left;
	Node *right;
	Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

//解题思路
//1.首先确定递归条件：递归函数传入的是叶节点的孩子节点的时候结束递归
//2.确定每个节点需要做的处理：
//3.(1) 当前节点的左节点不为空时，将左节点的next指针指向当前节点的右节点（不需要考虑右节点是否为空）；
//(2) 如果当前节点的next值不为null，则需要先找到当前节点的最右侧节点R（右节点不为null的时候为右节点，否则为左节点），之后再找到第一个左右节点不全为null的节点，找出其子节点中最左的不为null的节点L，当节点R和和节点L都不为空的时候，将R的next设置为L
//4.递归处理右子树
//5.递归处理左子树

/*
// Definition for a Node.
class Node {
public int val;
public Node left;
public Node right;
public Node next;

public Node() {}

public Node(int _val) {
val = _val;
}

public Node(int _val, Node _left, Node _right, Node _next) {
val = _val;
left = _left;
right = _right;
next = _next;
}
};
*/

class Solution {
	private void dfs(Node root) 
	{
		if (root == null) return;
		if (root.left != null) 
		{
			root.left.next = root.right;
		}
		if (root.next != null) 
		{
			Node leftNode = root.right != null ? root.right : root.left;
			Node rightRootNode = root.next;
			while (rightRootNode != null && rightRootNode.left == null && rightRootNode.right == null) 
			{
				rightRootNode = rightRootNode.next;
			}
			if (leftNode != null && rightRootNode != null) 
			{
				Node rightNode = rightRootNode.left != null ? rightRootNode.left : rightRootNode.right;
				leftNode.next = rightNode;
			}
		}
		dfs(root.right);
		dfs(root.left);
	}

	public Node connect(Node root) 
	{
		dfs(root);
		return root;
	}
}
