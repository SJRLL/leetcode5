����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���

���� s ���п��ܵķָ����

ʾ�� :

���� : "aab"
��� :
   [
	   ["aa", "b"],
	   ["a", "a", "b"]
   ]

//����˼·
//���ַ���ͷ����ʼ��ÿ�ν�ȡ�ַ����д��ڵĻ��ģ�ͨ�����ݷ�������⡣

class Solution {
		 public List<List<String>> partition(String s) 
		 {
			 ArrayList<List<String>> result = new ArrayList<List<String>>();
			 if (s.length() == 0) return result;
			 dfs(0, s, result, new ArrayList<String>());
			 return result;
		 }

		 public void dfs(int index, String s, List<List<String>> result, ArrayList<String> current){
			 //�������
			 if (index == s.length()) 
			 {
				 //��ӽ�����У�����java�洢�������⣬�����µ����飩
				 result.add(new ArrayList<String>(current));
				 return;
			 }
			 //���ַ����ָ�����ж��Ƿ�Ϊ����
			 for (int i = index; i <= s.length() - 1; i++)
			 {
				 //�ж���ѡ�Ƿ�Ϊ����
				 if (judge(s.substring(index, i + 1))) 
				 {
					 current.add(s.substring(index, i + 1));
					 //�ж�ʣ���ַ����Ƿ��ɶ�����Ĺ���
					 dfs(i + 1, s, result, current);
					 //����
					 current.remove(current.size() - 1);
				 }
			 }


		 }
		 //˫ָ���ж��Ƿ�Ϊ����
		 public boolean judge(String sub)
		 {
			 int first = 0;
			 int second = sub.length() - 1;
			 while (first < second)
			 {
				 if (sub.charAt(first) == sub.charAt(second))
				 {
					 first++;
					 second--;
				 }
				 else return false;
			 }
			 return true;
		 }
}