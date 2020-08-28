给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。



例如，给定三角形：

[
	[2],
	[3, 4],
	[6, 5, 7],
	[4, 1, 8, 3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

//解题思路
//在允许修改原数组的情况下，可以使用原地算法
//递减地枚举j，不需要使用额外空间
//由底到顶转移，不需要查找最小值

class Solution {
	public int minimumTotal(List<List<Integer>> triangle)
	{
		for (int i = triangle.size() - 2; i >= 0; i--)
		for (int j = i; j >= 0; j--)
			triangle.get(i).set(j, Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)) + triangle.get(i).get(j));
		return triangle.get(0).get(0);
	}
}
