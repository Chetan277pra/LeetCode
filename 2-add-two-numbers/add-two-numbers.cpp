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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        while(l1 and l2){
            int temp = l1->val + l2->val;
            if(carry) temp += 1, carry = false;
            if(temp > 9) temp -= 10, carry = true;
            ListNode* tt = new ListNode(temp);
            ans->next = tt;
            ans = ans->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            int temp = l1->val;
            if(carry) temp += 1, carry = false;
            if(temp > 9) temp -= 10, carry = true;
            ListNode* tt = new ListNode(temp);
            ans->next = tt;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            int temp = l2->val;
            if(carry) temp += 1, carry = false;
            if(temp > 9) temp -= 10, carry = true;
            ListNode* tt = new ListNode(temp);
            ans->next = tt;
            ans = ans->next;
            l2 = l2->next;
        }
        if(carry) {
            ListNode* tt = new ListNode(1);
            ans->next = tt;
        }
        return res->next;
    }
};