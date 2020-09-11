老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1 :
输入 : [1, 0, 2]
输出 : 5
解释 : 你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例 2 :
输入 : [1, 2, 2]
输出 : 4
解释 : 你可以分别给这三个孩子分发 1、2、1 颗糖果。
第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

//解题思路
//dp思想，先left2right，记录每个孩子左侧对他的影响，再right2left，记录每个孩子右侧对他的影响。
//为了满足评分高的孩子糖果数要大于左右相邻孩子的糖果，必须取Max，这样糖果数最少且满足规则。
//核心：为了糖果数最少，要取max

class Solution {
		 public int candy(int[] ratings) {
			 int[] left = new int[ratings.length];
			 int[] right = new int[ratings.length];
			 for (int i = 1; i < left.length; i++) {
				 if (ratings[i] > ratings[i - 1]) {
					 left[i] = left[i - 1] + 1;
				 }
			 }
			 for (int i = right.length - 2; i >= 0; i--) {
				 if (ratings[i] > ratings[i + 1]) {
					 right[i] = right[i + 1] + 1;
				 }
			 }
			 int count = ratings.length;
			 for (int i = 0; i < ratings.length; i++) {
				 count += Math.max(left[i], right[i]);
			 }
			 return count;
		 }
 }

