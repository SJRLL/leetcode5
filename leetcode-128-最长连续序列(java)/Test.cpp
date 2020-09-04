给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例 :

输入 : [100, 4, 200, 1, 3, 2]
输出 : 4
解释 : 最长连续序列是[1, 2, 3, 4]。它的长度为 4。

//解题思路
//优先队列解法，小顶堆，取出元素是O(1)，再用O(logn)维护队列。最后再遍历一遍队列，所以最终还是O(n)的时间复杂度。

class Solution {
	public int longestConsecutive(int[] nums) 
	{
		if (nums.length == 0) return 0;
		Queue<Integer> q = new PriorityQueue<>();
		for (int i = 0; i < nums.length; i++)
			q.offer(nums[i]);

		int ans = 0;
		int cnt = 1;
		int pre = q.poll();
		while (!q.isEmpty())
		{
			if (pre == q.peek())
			{
				q.poll();
				continue;
			}
			if (pre + 1 == q.peek())
			{
				cnt++;
			}
			else
			{
				ans = Math.max(ans, cnt);
				cnt = 1;
			}
			pre = q.poll();
		}
		return Math.max(ans, cnt);
	}
}
