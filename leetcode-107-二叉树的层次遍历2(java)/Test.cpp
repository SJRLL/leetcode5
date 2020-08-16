����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
����������[3, 9, 20, null, null, 15, 7],

  3
 / \
9  20
  / \
 15  7
�������Ե����ϵĲ�α���Ϊ��

[
	[15, 7],
	[9, 20],
	[3]
]

//����˼·
//��Ҫ����һ�㣬ArrayList���ϵ�ʹ�ã�����ʹ�����صķ�ʽ��add������ÿ�ζ���ӵ����ϵ�����Ϊ0��λ�ã�
//�����Ϳ��Է������������Ԫ���ˡ�

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

		//ʹ��BFS�㷨��������
		List<List<Integer>> res = new ArrayList<>();

		//��������ж�
		if (root == null){
			return res;
		}

		//����һ������
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
