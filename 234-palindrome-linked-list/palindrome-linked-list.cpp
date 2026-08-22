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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        int s = 0;
        ListNode* temp = head;
        while(temp){
            s++;
            temp = temp->next;
        }
        int mid = s/2;
        int cnt = 0;
        ListNode *prev = nullptr, *curr = head, *aage = head->next;
        while(cnt < mid){
            cnt++;
            curr->next = prev;
            prev = curr;
            curr = aage;
            aage = aage->next;
        // cout << prev->val << " " << curr->val<<endl;
        }
        if(s%2) curr = aage;
        while(prev and curr){
            if(prev->val != curr->val ) return false;
            prev = prev->next;
            curr = curr->next;
        }
        if(!prev and !curr) return true;
        return false;
    }
};