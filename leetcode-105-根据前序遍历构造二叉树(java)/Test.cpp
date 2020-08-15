����һ������ǰ�������������������������

ע�� :
����Լ�������û���ظ���Ԫ�ء�

���磬����
ǰ����� preorder = [3, 9, 20, 15, 7]
������� inorder = [9, 3, 15, 20, 7]
�������µĶ�������

  3
 / \
 9  20
   / \
  15  7


//����˼·
//����һ����������Ҫ���������֣�root����������������
//���������������Ĺ������ְ�����root����������������
//�ؼ����ڶ�λ�����ڵ㣬���ֳ�����������Ȼ�� �ݹ� ������������

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
		if (pre == preorder.length) return null; // pre�ߵ�preorderĩβ
		if (inorder[in] == stop) 
		{ // inָ���ߵ���ֹͣ��
			in++; // stop������ˣ�in�ƽ�һλ
			return null;
		}
		TreeNode node = new TreeNode(preorder[pre++]);
		node.left = build(preorder, inorder, node.val);
		// ��������ֹͣ���ǵ�ǰ�ĸ��ڵ��ֵ
		node.right = build(preorder, inorder, stop);
		// ��������ֹͣ���ǵ�ǰ����ֹͣ��
		return node;
	}
}
