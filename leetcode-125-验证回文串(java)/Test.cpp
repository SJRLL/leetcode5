
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

���� : "A man, a plan, a canal: Panama"
��� : true
	 ʾ�� 2 :

���� : "race a car"
��� : false

//����˼·
//��������˫ָ�룬����һ�����飬���������ֻ���ĸ��jƫ��ָ�롣

class Solution {
		 public boolean isPalindrome(String s) {
			 int left = 0;
			 int right = s.length() - 1;
			 while (right >= left)
			 {
				 //���������ֻ���ĸ����
				 if (!Character.isLetterOrDigit(s.charAt(left)))
				 {
					 left++;
					 continue;
				 }
				 if (!Character.isLetterOrDigit(s.charAt(right)))
				 {
					 right--;
					 continue;
				 }
				 //�ж��Ƿ����
				 if (right >= left && Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))) 
				 {
					 left++;
					 right--;
				 }
				 else return false;
			 }
			 return true;
		 }
}
