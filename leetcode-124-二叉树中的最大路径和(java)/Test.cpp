
����һ���ǿն����������������·���͡�

�����У�·��������Ϊһ������������ڵ�������ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣

ʾ�� 1:

���� : [1, 2, 3]

	 1
	/ \
	2   3

���: 6

ʾ�� 2 :

���� : [-10, 9, 20, null, null, 15, 7]

	 - 10
	 / \
	 9  20
	   / \
	  15   7

 ���: 42

//����һ���ݹ�
//����˼·��
//(1) �Ӹ��ڵ㿪ʼ�ݹ���㾭��ÿ���ڵ�����·���͡�
//(2) �ݹ���ɷ������������������·���͡�

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
		 int maxSum = Integer.MIN_VALUE;

		 public int maxPathSum(TreeNode root) 
		 {
			 // �Ӹ��ڵ㿪ʼ�ݹ���㡣
			 maxGain(root);
			 return maxSum;
		 }

		 public int maxGain(TreeNode node) 
		 {
			 if (node == null) 
			 {
				 return 0;
			 }

			 // ֻ�������ӽڵ�������ֵ���� 0 ����ǰ�ڵ�������ֵ�Ż���
			 int leftGain = Math.max(maxGain(node.left), 0);
			 int rightGain = Math.max(maxGain(node.right), 0);

			 // �ڵ�����·����ȡ���ڸýڵ��ֵ��ýڵ�������ӽڵ�������ֵ��
			 int priceNewpath = node.val + leftGain + rightGain;

			 // �������ͼ�¼��
			 maxSum = Math.max(maxSum, priceNewpath);

			 // ���ص�ǰ�ڵ�������ֵ��
			 return node.val + Math.max(leftGain, rightGain);
		 }
}
