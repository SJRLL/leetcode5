����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�

˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

 ʾ�� :
�������¶��������Լ�Ŀ��� sum = 22��

      5
     / \
    4   8
   /   / \
  11  13  4
 / \       \
7   2       1
���� true, ��Ϊ����Ŀ���Ϊ 22 �ĸ��ڵ㵽Ҷ�ӽڵ��·�� 5->4->11->2��

//����˼·��
//�ݹ鷨��˼·���£�
//1���ж�������Ƿ�Ϊ�գ�Ϊ����һ������false��
//2�������ǰ�����Ҷ�ӽ�㣬��ô���sum���ڴ˽���ֵ�򷵻�true��
//3������������������������ǰ�����������㡰���ڴӸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���sum��ȥ��ǰ����ֵ������ô����true��

class Solution {
	public boolean hasPathSum(TreeNode root, int sum) 
	{
		if (root == null) 
			return false;
		if (root.left == null && root.right == null && sum == root.val) 
			return true;
		return (hasPathSum(root.left, sum - root.val)) || (hasPathSum(root.right, sum - root.val));
	}
}
