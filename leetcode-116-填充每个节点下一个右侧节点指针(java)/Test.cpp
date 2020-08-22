给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
	int val;
	Node *left;
	Node *right;
	Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。



示例：



输入：{ "$id":"1", "left" : {"$id":"2", "left" : {"$id":"3", "left" : null, "next" : null, "right" : null, "val" : 4}, "next" : null, "right" : {"$id":"4", "left" : null, "next" : null, "right" : null, "val" : 5}, "val" : 2}, "next" : null, "right" : {"$id":"5", "left" : {"$id":"6", "left" : null, "next" : null, "right" : null, "val" : 6}, "next" : null, "right" : {"$id":"7", "left" : null, "next" : null, "right" : null, "val" : 7}, "val" : 3}, "val" : 1 }

输出：{ "$id":"1", "left" : {"$id":"2", "left" : {"$id":"3", "left" : null, "next" : {"$id":"4", "left" : null, "next" : {"$id":"5", "left" : null, "next" : {"$id":"6", "left" : null, "next" : null, "right" : null, "val" : 7}, "right" : null, "val" : 6}, "right" : null, "val" : 5}, "right" : null, "val" : 4}, "next" : {"$id":"7", "left" : {"$ref":"5"}, "next" : null, "right" : {"$ref":"6"}, "val" : 3}, "right" : {"$ref":"4"}, "val" : 2}, "next" : null, "right" : {"$ref":"7"}, "val" : 1 }

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

//解题思路
//由题目与案例可以得出，需要添加的next大致分为三种情况：
//（1）最右端节点指向null
//（2）每个节点的左右孩子节点由左指向右
//（3）不同子树之间最右端节点指向最左端节点

class Solution {
	public Node connect(Node root) {
		if (root == null) return root;
		bfs3(root);
		if (root.left != null)
		{
			bfs1(root);
			if (root.left.right != null)
			{
				bfs2(root.left, root.right);
			}
		}
		return root;
	}
	//处理同一节点下左右节点的连接
	public void bfs1(Node current)
	{
		if (current.left == null) return;
		current.left.next = current.right;
		bfs1(current.left);
		bfs1(current.right);
	}
	//处理不同子树下节点之间的连接
	public void bfs2(Node current, Node next)
	{
		current.right.next = next.left;
		if (current.left.left != null)
		{
			//子树的上一个根节点相同
			bfs2(current.left, current.right);
			bfs2(next.left, next.right);
			//子树的上一个根节点不同
			bfs2(current.right, next.left);
		}
	}
	//处理最右端节点的连接
	public void bfs3(Node current)
	{
		current.next = null;
		if (current.right != null) bfs3(current.right);
	}
}
