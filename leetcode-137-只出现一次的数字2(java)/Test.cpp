给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入 : [2, 2, 3, 2]
输出 : 3

示例 2 :
输入 : [0, 1, 0, 1, 0, 1, 99]
输出 : 99

//解题思路：
//1.位运算求解此题;
//2.如果把所有出现三次的数字的二进制表示的每一位加起来, 那么每一位都能被3整除;
//3.如果某一位的和能被3整除, 那么只出现一次数字的二进制位中对应的那一位就是0, 否则就是1;

public int singleNumber(int[] nums) 
{
	if (nums == null || nums.length <= 0)
		throw new RuntimeException("数组不合法");

	int[] bits = new int[32];

	for (int j = 0; j < bits.length; j++) 
	{
		for (int i = 0; i < nums.length; i++) 
		{ // 每一位数字对应的0或1加起来
			int num = nums[i] >> j;
			bits[j] += (num & 1);
		}
	}

	int result = 0;
	for (int i = bits.length - 1; i >= 0; i--) 
	{
		result <<= 1;
		result += bits[i] % 3;
	}
	return result;
}
