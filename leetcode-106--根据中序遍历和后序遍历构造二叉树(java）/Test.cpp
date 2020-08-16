����һ��������������������������������

ע�� :
����Լ�������û���ظ���Ԫ�ء�

���磬����
������� inorder = [9, 3, 15, 20, 7]
������� postorder = [9, 15, 7, 20, 3]
�������µĶ�������

  3
 / \
9  20
   / \
  15  7


//����˼·
//������Ժ�ǰ�򡢺��򡢲��������һ������������Ψһ�Ķ�������
//��û���������������д��䶼�޷�����Ψһ�Ķ���������Ϊ���򡢺��򡢲��������ṩ����㣬ֻ�����������������������

class Solution {
	private int[] post; //��������
	private Map<Integer, Integer> map; //��ϣ���¼���ֵ����������±�

	public TreeNode buildTree(int[] inorder, int[] postorder) 
	{
		post = postorder;
		map = new HashMap<>();
		for (int i = 0; i < inorder.length; i++)
			map.put(inorder[i], i);
		return helper(0, inorder.length - 1, post.length - 1);
	}

	/**
	* ��������ʼĩ�±깹����
	* @param begin �������ʼ�±�
	* @param end ����Ľ����±�
	* @param postidx ������ں�������±�
	* @return �������ĸ����
	*/
	private TreeNode helper(int begin, int end, int postidx) 
	{
		if (begin > end)    return null; //û�н�㣬���ؿ���
		int rootidx = map.get(post[postidx]); //���������������±꣬����������������
		TreeNode root = new TreeNode(post[postidx]);
		int rightcnt = end - rootidx; //�����������
		root.left = helper(begin, rootidx - 1, postidx - rightcnt - 1); //�������������򹹽�����
		root.right = helper(rootidx + 1, end, postidx - 1);
		return root;
	}
}

