给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明 :

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。

你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1 :
输入 :
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot", "dot", "dog", "lot", "log", "cog"]

输出 : 5
解释 : 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	  返回它的长度 5。

示例 2 :

输入 :
	 beginWord = "hit"
	 endWord = "cog"
	 wordList = ["hot", "dot", "dog", "lot", "log"]

输出 : 0
解释 : endWord "cog" 不在字典中，所以无法进行转换。

//解题思路：BFS
class Solution {
	 public int ladderLength(String beginWord, String endWord, List<String> wordList) {
			 Queue<String> queue = new LinkedList<>();
			 Set isVisited = new HashSet();
			   //建立一个图，里面存字典里所有的字符（包括beginword）可以直接达到的字符串
			   Map<String, List<String>> map = new HashMap<>();
			   wordList.add(beginWord);
			   for (String s : wordList){
				   map.put(s, change1Bit(wordList, s));
			   }
			   queue.offer(beginWord);
			   int count = 1;
			   while (!queue.isEmpty()){
				   int size = queue.size();
				   for (int m = 0; m<size; m++){
					   String cur = queue.poll();
					   isVisited.add(cur);

					   if (cur.equals(endWord)){
						   return count;
					   }
					   //System.out.println(cur);
					   //System.out.println(change1Bit(wordList,cur));
					   for (String c : map.get(cur)){
						   if (isVisited.contains(c)){
							   continue;
						   }
						   queue.offer(c);
					   }
				   }

				   count++;
			   }
			   return 0;
		   }
		   //给定一个字符串s，一个字典wordList，从字典中找出所有s变化1位后能变成的结果
		   public List<String> change1Bit(List<String> wordList, String s){
			   List<String> list = new ArrayList<>();
			   int len = s.length();
			   for (String c : wordList){
				   int count = 0;
				   for (int i = 0; i<len; i++){
					   if (c.charAt(i) != s.charAt(i)){
						   count++;
					   }
					   //如果有两位不一致，这个字符c就不满足条件，直接跳到下一个字符
					   if (count == 2){
						   break;
					   }
				   }
				   //遍历完c后如果不一致位小于2，就把c加入到list中
				   if (count<2){
					   list.add(c);
				   }
			   }
			   return list;
		 }
}
