给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。


示例 1：
输入：head = [3, 2, 0, -4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1, 2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


//解题思路：
//环形链表，即原本末尾的节点的 next 指针，指向了链表的任意一个节点，形成了一个闭环。
//在这种环形链表中，遍历时会停不下来，因为在环中会一直循环，这是它的特点。

//如果对于哈希表熟悉的话，我们很容易能想到通过哈希表来存储已经遍历的节点，然后判断下个要遍历的节点是否已经在哈希表里存在：
//若存在则说明是环，否则直到遍历结束也没有找到，那说明不是环。

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

//通过哈希表存储判断
public class Solution {
	public boolean hasCycle(ListNode head) {
		if (head == null || head.next == null) return false;
		// HashSet用于存储遍历过的节点
		HashSet<ListNode> set = new HashSet<>();
		ListNode cur = head;
		while (cur.next != null) 
		{
			if (!set.add(cur)) 
			{
				return true;
			}
			cur = cur.next;
		}
		return false;
	}
}


//2、通过快慢指针是否会相遇来判断
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
	public boolean hasCycle(ListNode head)
	{
		if (head == null || head.next == null) return false;
		// 慢指针
		ListNode slow = head;
		// 快指针
		ListNode fast = head;
		while (fast.next != null && fast.next.next != null) 
		{
			// 慢指针每次走一步
			slow = slow.next;
			// 快指针每次走两步
			fast = fast.next.next;
			// 当快慢指针相同时，则说明是在圆环里面
			if (slow == fast) 
			{
				return true;
			}
		}
		return false;
	}
}

