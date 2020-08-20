给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。



示例 1：

输入：S = "rabbbit", T = "rabbit"
输出：3
解释：

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2：

输入：S = "babgbag", T = "bag"
输出：5
解释：

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
^  ^^
babgbag
^^^

//解题思路：典型的动态规划，找状态方程
//（一）状态

//f[i][j]表示s1的前i个字符的子序列中，包含多少个s2的前 j 个字符子串

//（二）转移方程

//如果s1的第 i 个字符和s2的第 j 个字符不同的话，
//意味着s1的第 i 个字符，必不参与组成子序列

//f[i][j] = f[i - 1][j]
//（例如 abc, ab) f[3][2] = f[2][2]
//如果s1的第 i 个字符和s2的第 j 个字符相同的话，
//意味着s1的第 i 个字符，可以参与组成子序列，也可不参与组成子序列

//f[i][j] = f[i - 1][j - 1] + f[i - 1][j]
//(例如 abcc, abc) f[4][3] = f[3][2] + f[3][3]

//（三）初始化

//s1的前 i 个字符和s2的前 0 个字符，意味着 s1 中子序列等于空串的个数都是 1
//f[i][0] = 1

//（四）结果

//f[m][n]

class Solution {
	public int numDistinct(String s1, String s2)
	{
		int m = s1.length(), n = s2.length();
		int[][] f = new int[m + 1][n + 1];

		for (int i = 0; i <= m; i++) f[i][0] = 1;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i][j] = f[i - 1][j];
				if (s1.charAt(i - 1) == s2.charAt(j - 1))
				{
					f[i][j] += f[i - 1][j - 1];
				}
			}
		}
		return f[m][n];
	}
}
