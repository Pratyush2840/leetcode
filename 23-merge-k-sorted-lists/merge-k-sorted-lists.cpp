class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;

        for (ListNode* head : lists) {
            if (head)
                pq.push({head->val , head});
        }
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        while (!pq.empty()) {
            ListNode* t = pq.top().second;
            pq.pop();
            temp->next = t;
            temp = temp->next;
            if (t->next)pq.push({t->next->val ,t->next});
        }
        temp->next = nullptr;

        return head->next;
    }
};