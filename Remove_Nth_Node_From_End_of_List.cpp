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
 * ɨ��һ�ּ����ҵ�������n���ڵ�ķ�����
 * 1��������һ��ָ�룬��������n-1��λ�ã�
 * 2����ͬʱ�ƶ�����ָ�룬ֱ�������õ��Ǹ�ָ�뵽��������β����
 * 3����ʱǰ���ָ��ָ��ļ�Ϊ������n���ڵ㣻
 * 4��Ϊ�˴ﵽɾ����Ŀ�ģ�ʵ����ɾ��������n���ڵ㻹��Ҫ��3��ָ�룬ָ��Ҫɾ���Ľڵ��ǰһ���ڵ㡣
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
 * �Ľ�������
 * �ʼ�����õ�ָ�룬��������n��λ�ã������Ϳ�������һ��ָ��Ϳ���ɾ��������n���ڵ㡣
 */
