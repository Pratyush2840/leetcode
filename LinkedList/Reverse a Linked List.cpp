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
    ListNode* ans = new ListNode();
    void f(ListNode* node  , ListNode* parent){
        if(node->next != NULL){
            f(node->next , node);
        }
        else{
            ans = node;
        }
        node->next = parent;

    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return NULL;
        f(head , NULL);
        return ans;
    }
};