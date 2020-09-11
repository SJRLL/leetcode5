给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入 : [2, 2, 1]
输出 : 1

示例 2 :
输入 : [4, 1, 2, 1, 2]
输出 : 4


//解题思路
//题目说 其余每个元素均出现两次，那么当元素第一次出现，则添加到数组，再次出现则删除该元素
//除了某个元素只出现一次以外，那么剩下的最后一个元素 就是题解

def singleNumber(nums) :
no_duplicate_list = []
		 for num in nums :
		 if num not in no_duplicate_list :
		 no_duplicate_list.append(num)
		 else :
		 no_duplicate_list.remove(num)
		 return no_duplicate_list.pop() # 在 数组中取出该数字

//方法二 位运算
//解题思路
//交换律： p⊕q = q⊕pp⊕q = q⊕p
// 结合律： p⊕(q⊕r) = (p⊕q)⊕rp⊕(q⊕r) = (p⊕q)⊕r
//恒等率： p⊕0 = pp⊕0 = p
//归零率： p⊕p = 0p⊕p = 0

class Solution {
			 public int singleNumber(int[] nums) 
			 {
				 int sum = 0;
				 for (int i = 0; i<nums.length; i++) {

					 sum ^= nums[i]; // 异或
				 }
				 return sum;

			 }
}