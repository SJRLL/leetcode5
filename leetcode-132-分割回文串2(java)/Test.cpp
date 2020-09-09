给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例 :
输入 : "aab"
输出 : 1
解释 : 进行一次分割就可将 s 分割成["aa", "b"] 这样两个回文子串。

//解题思路
//预处理：
//通过 O(n ^ 2) 的预处理得到二维数组 palindrome[i][j] ，表示 s[i]~s[j] 子串是否为回文串
	
//状态：
//dp[i]: s[0]~s[i] 的最少分割次数，i从0开始
	 
//状态转移：
//dp[i] = min(i, min(dp[k] + 1)) k 满足 k < i && palindrome[k][i] == true
	 
//结果：
//dp[s.len - 1]

class Solution {
	public int minCut(String s) 
	{
		if (s == null || s.length() == 0) return 0;

		boolean[][] palindrome = new boolean[s.length()][s.length()];
		for (int i = 0; i < s.length(); i++)
		{
			palindrome[i][i] = true;
			for (int j = 0; j <= 1; j++) 
			{
				int left = i - j;
				int right = i + 1;
				while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) 
				{
					palindrome[left][right] = true;
					left--;
					right++;
				}
			}
		}

		int[] dp = new int[s.length()];

		for (int i = 0; i < s.length(); i++) 
		{
			if (palindrome[0][i]) 
			{
				dp[i] = 0;
			}
			else
			{
				dp[i] = i;
				for (int j = i; j > 0; j--) 
				{
					if (palindrome[j][i]) 
					{
						if (1 + dp[j - 1] < dp[i]) 
						{
							dp[i] = 1 + dp[j - 1];
						}
					}
				}
			}
		}

		return dp[s.length() - 1];
	}
}

