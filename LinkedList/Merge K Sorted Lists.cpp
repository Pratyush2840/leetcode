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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();

            temp->next = t;
            temp = temp->next;

            if (t->next)
                pq.push(t->next);
        }
        temp->next = nullptr;

        return head->next;
    }
};