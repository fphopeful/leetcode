/* 
 * Problem 19:	Remove Nth Node From End of List
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass
 */

/* 
 * 扫描一轮即可找到倒数第n个节点的方法：
 * 1、多设置一个指针，先往后移n-1个位置；
 * 2、再同时移动两个指针，直到多设置的那个指针到达了链表尾部；
 * 3、此时前面的指针指向的即为倒数第n个节点；
 * 4、为了达到删除的目的，实际上删除倒数第n个节点还需要第3个指针，指向要删除的节点的前一个节点。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *p3 = head;
        int i;
        for (i = 1; i < n; i++)
            p1 = p1->next;
        while(p1->next != NULL) {
            p1 = p1->next;
            p3 = p2;
            p2 = p2->next;
        }
        if (p2 == head) {
            head = p2->next;
        } else {
            p3->next = p2->next;
            p2->next = NULL;
        }
        delete p2;
        return head;
    }
};

/*
 * 改进方法：
 * 最开始多设置的指针，先往后移n个位置，这样就可以少用一个指针就可以删除倒数第n个节点。
 */
