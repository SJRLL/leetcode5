给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。

说明：不允许修改给定的链表。



示例 1：

输入：head = [3, 2, 0, -4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1, 2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

//解题思路
//快慢指针的思路，主要的解题思路其实是数学问题。将链表分成两部分，环外链表设有a个节点，环内有b个节点，
//设fast指针每次走两步，slow指针每次走一步。则当fast走过2a时slow走过了a，到达了环的入口，这时候fast指针要追上slow指针，
//要走过nb - a，而此时slow已经走过了a，fast已经走过了2a。则追上时，fast走过了a + nb，slow走过了nb路程。
//这是我们将fast指针重新指向链表头head，并让fast每次也走一步，则fast与slow在这时的第一次相遇时，fast走过了a，slow走过了a + nb刚好在环入口处相遇。
//此时fast与slow都指向了环入口。

/**
* Definition for singly-linked list.
* class ListNode {
*     int val;
*     ListNode next;
*     ListNode(int x) {
*         val = x;
*         next = null;
*     }
* }
*/
public class Solution {
	public ListNode detectCycle(ListNode head) {
		ListNode fast = head;
		ListNode slow = head;

		for (; fast != null;)
		{
			fast = fast.next;
			if (fast == null)
			{
				return null;
			}
			fast = fast.next;
			slow = slow.next;

			if (fast == slow)
			{
				fast = head;
				for (;;){
					if (slow == fast)
					{
						return slow;
					}
					fast = fast.next;
					slow = slow.next;
				}
			}
		}

		return null;
	}
}


