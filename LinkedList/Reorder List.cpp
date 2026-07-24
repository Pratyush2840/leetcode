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
    ListNode* ans = NULL;

    // Recursive function to reverse the linked list
    void f(ListNode* node, ListNode* parent) {
        if (node->next != NULL) {
            f(node->next, node);
        } else {
            // Last node becomes the new head
            ans = node;
        }

        // Reverse the link
        node->next = parent;
    }

    // Reverse linked list
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        f(head, NULL);

        // Old head becomes the last node
        head->next = NULL;

        return ans;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* second = slow->next;
        slow->next = NULL;

        // Reverse the second half
        second = reverseList(second);

        // Merge both halves alternately
        ListNode* first = head;

        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};