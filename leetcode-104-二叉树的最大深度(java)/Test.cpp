����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
����������[3, 9, 20, null, null, 15, 7]��

    3
   / \
   9  20
	  / \
	 15  7

//����˼·
//�ݹ�DFS��BFSʵ�֡�
//DFS�͵ݹ�ÿһ����㣬���Ϊ�վͷ���0������ͷ������������߶ȸ����ߵ���ֵ�ӱ����1,BFS���ư��������������ÿ���㣬��¼���ٲ㡣

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
	//�ݹ飬����DFS
	public int maxDepth(TreeNode root) {//�ݹ�ÿһ����㣬���Ϊ�վͷ���0������ͷ������������߶ȸ����ߵ���ֵ�ӱ����1
		return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
	}
	//BFS
	public int maxDepth(TreeNode root) 
	{
		if (root == null) return 0;
		Queue<TreeNode> queue = new LinkedList<>();//ʹ�ö���ʵ��BFS
		int height = 0;
		queue.offer(root);
		while (!queue.isEmpty())
		{
			int size = queue.size();//ʹ��һ��������ʵ�����ư���������龰
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
