给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入 : s = "leetcode", wordDict = ["leet", "code"]
输出 : true
解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
	   
示例 2：
输入 : s = "applepenapple", wordDict = ["apple", "pen"]
输出 : true
解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
注意你可以重复使用字典中的单词。

示例 3：
输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出 : false

//解题思路
//用for循环遍历字符串，设置子串起始处为i, 末端为j，判断子串是否出现在字典中，则会出现两种情况：
//(1)出现, 则以该子串的末端为新子串的起始处, 继续往后遍历, 若判断到最后也出现，则返回true
//(2)不出现，则继续往后遍历看看后面的子串是否出现，若判断到最后也不出现，则返回false

class Solution {
	public boolean wordBreak(String s, List<String> wordDict) 
	{
		Set<String> set = new HashSet<>(wordDict);
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			int j = i + 1;
			while (j <= len)
			{
				if (j == len && !set.contains(s.substring(i, len))) return false;

				String str = s.substring(i, j);
				if (set.contains(str))
				{
					i = j - 1;
					break;
				}
				j++;
			}
			if (i == len - 1) return true;
		}
		return false;
	}
}
}

