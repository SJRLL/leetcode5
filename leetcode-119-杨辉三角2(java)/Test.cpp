//����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�

//����: 3
//��� : [1, 3, 3, 1]

//����˼·��
//ֱ���������㣬��n�е�m��������C(m, n), ���ݹ�ʽC(n, m) = n!/ ((n - m)!* m!)�Ϳ��������
///������󲿷�������Լ�����������ᳬint������Ҫѧ�ữ������������long����
//����33����˵����0������1����1������33 / 1����2������33 / 1 * 32 / 2����3������33 / 1 * 32 / 2 * 31 / 3��������
//�Դ����ƣ�����17�����ͺ��ˣ���18����ǰ���Ѿ�����ˣ�ֱ��forѭ��������ӾͿ�����

class Solution {
	static Integer fun(Integer aa, int n, int m)
	{
		long  sum = aa;
		sum = sum*n / m;
		return (int)sum;
	}
	public List<Integer> getRow(int rowIndex) 
	{
		int j = rowIndex / 2;
		List<Integer> list = new ArrayList<>();
		list.add(1);
		for (int i = 1; i <= rowIndex; i++, rowIndex--)
		{
			list.add(fun(list.get(i - 1), rowIndex, i));
		}
		for (int i = 0; i<j; i++)
		{
			list.add(list.get(j - i - 1));
		}
		return list;
	}
}
