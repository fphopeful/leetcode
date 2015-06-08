/* 
 * Problem 203:	Remove Linked List Elements
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

/* 
 * 链表的基本操作.
 * 虽然此题比较简单，但是head的操作、p何时遍历到下一个都是易错点.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head, *tmp = NULL;
        if (head == NULL)
            return head;
        while (p != NULL) {
            if (head->val == val) {
                p = head->next;
                delete(head);
                head = p;
                continue;
            }
            if (p->next == NULL)
                break;
            if (p->next->val == val) {
                tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                tmp = NULL;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};
