
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入 : "A man, a plan, a canal: Panama"
输出 : true
	 示例 2 :

输入 : "race a car"
输出 : false

//解题思路
//采用左右双指针，遍历一遍数组，遇到非数字或字母的j偏移指针。

class Solution {
		 public boolean isPalindrome(String s) {
			 int left = 0;
			 int right = s.length() - 1;
			 while (right >= left)
			 {
				 //遇到非数字或字母跳过
				 if (!Character.isLetterOrDigit(s.charAt(left)))
				 {
					 left++;
					 continue;
				 }
				 if (!Character.isLetterOrDigit(s.charAt(right)))
				 {
					 right--;
					 continue;
				 }
				 //判断是否相等
				 if (right >= left && Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))) 
				 {
					 left++;
					 right--;
				 }
				 else return false;
			 }
			 return true;
		 }
}
