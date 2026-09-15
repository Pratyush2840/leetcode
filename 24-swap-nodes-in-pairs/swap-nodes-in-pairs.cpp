/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        } 
        ListNode* a = head;
        ListNode* prev;
        ListNode* b = head->next;
        head = b;
        while (a->next != NULL && b != NULL) {
            prev = a;
            a->next = a->next->next;
            b->next = a;
            a = a->next;
            if (a == NULL) {
                break;
            }
            b = a->next;
            if(b!=NULL) prev->next = b;
            prev = prev;
        }
        return head;
    }
};