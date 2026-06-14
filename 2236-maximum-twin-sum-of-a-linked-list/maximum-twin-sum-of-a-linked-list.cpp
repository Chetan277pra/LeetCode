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
    int ans = 0;
    void rec(ListNode* &head , ListNode* last){
        if(last == NULL){
            return;
        }
        rec(head , last->next);
        ans = max(ans , head->val + last->val);
        head = head->next;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* last = head;
        rec(head , last);
        return ans;
    }
};