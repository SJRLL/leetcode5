给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入 :
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出 :
   [
	   "cats and dog",
	   "cat sand dog"
   ]

示例 2：
输入 :
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出 :
   [
	   "pine apple pen apple",
	   "pineapple pen apple",
	   "pine applepen apple"
   ]
解释 : 注意你可以重复使用字典中的单词。

示例 3：
输入 :
	 s = "catsandog"
		 wordDict = ["cats", "dog", "sand", "and", "cat"]
	 输出 :
		[]


//思路过程：
//1.获取wordDict的长度序列，就是其中包含几种不同类型的长度，方便后面按照字典中出现的长度进行截取dfs, 加快搜索过程；
//2.进行dfs的搜索，中间使用一个dp数组来进行记忆化进行剪枝 dp[start][len]表示从s的start位置开始截取长度为len是否能够得到最后正确的解
//如果不能返回 - 1，则进行剪枝；否则继续进行dfs寻找全部的最优解

class Solution {
		 List<String> ans;
		 Set<Integer> lenset;//长度种类
		 Set<String> wordSet;//单词的字典，方便查询
		 String s;
		 int[][] dp;//进行记忆化剪枝的数组
		 private String gen(List<String> str)
		 {
			 //生成给定的输出模型
			 StringBuilder sb = new StringBuilder();
			 boolean first = true;
			 for (String s : str)
			 {
				 if (first)
				 {
					 first = false;
					 sb.append(s);
				 }
				 else sb.append(" ").append(s);
			 }
			 return sb.toString();
		 }
		 private int helper(List<String> temp, int start)
		 {
			 if (start == s.length())
			 {
				 //能够正确拆分单词，返回1
				 ans.add(gen(temp));
				 return 1;
			 }
			 boolean ok = false;//标记
			 for (int len : lenset)
			 {
				 if (start + len <= s.length())
				 {
					 String st = s.substring(start, start + len);
					 if (wordSet.contains(st) && dp[start][len] != -1){//如果已经不可拆分，直接剪枝
						 temp.add(st);
						 dp[start][len] = helper(temp, start + len);
						 if (dp[start][len] == 1) ok = true;
						 temp.remove(temp.size() - 1);
					 }
				 }
			 }
			 if (ok == false)
				 return -1;
			 else return 1;
		 }
		 public List<String> wordBreak(String s, List<String> wordDict)
		 {
			 ans = new ArrayList<>();
			 lenset = new HashSet<>();
			 wordSet = new HashSet<>();
			 this.s = s;
			 int max = 0;
			 for (int i = 0; i<wordDict.size(); i++)
			 {
				 max = Math.max(max, wordDict.get(i).length());
				 lenset.add(wordDict.get(i).length());
				 wordSet.add(wordDict.get(i));
			 }
			 dp = new int[s.length() + 1][max + 1];
			 helper(new ArrayList<String>(), 0);
			 return  ans;
		 }
}
