
����һ����������ԭ�ؽ���չ��Ϊһ��������



���磬����������

    1
   / \
  2   5
 / \   \
3   4   6
����չ��Ϊ��

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

//����˼·��
//�۲�ö�������չ���������֪������Ԫ��˳�����������������˳��һ�£��Ҷ�������ָ��ָ���̽ڵ㣬��ָ��Ϊnull��
//��ˣ����ǿ��������������������ÿ��Ԫ����ӣ�����������ýڵ�ָ���̣���ָ�븳��ֵ��

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
