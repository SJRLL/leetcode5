����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�

���ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣



���磬���������Σ�

[
	[2],
	[3, 4],
	[6, 5, 7],
	[4, 1, 8, 3]
]
�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����

//����˼·
//�������޸�ԭ���������£�����ʹ��ԭ���㷨
//�ݼ���ö��j������Ҫʹ�ö���ռ�
//�ɵ׵���ת�ƣ�����Ҫ������Сֵ

class Solution {
	public int minimumTotal(List<List<Integer>> triangle)
	{
		for (int i = triangle.size() - 2; i >= 0; i--)
		for (int j = i; j >= 0; j--)
			triangle.get(i).set(j, Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)) + triangle.get(i).get(j));
		return triangle.get(0).get(0);
	}
}
