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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot = 0;
        ListNode* temp = head;
        while(temp) {
            tot++;
            temp = temp->next;
        }
        int need = tot - n - 1;
        int curr = 0;
        temp = head;
        while(curr < need) curr++ , temp = temp->next;
        if(need < 0) head = head->next;
        else if(temp->next){
            temp->next = temp->next->next;
        }
        else temp->next = nullptr;
        return head;
    }
};