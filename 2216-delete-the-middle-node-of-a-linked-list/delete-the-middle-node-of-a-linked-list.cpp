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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp) count++, temp = temp->next;
        int mid = count/2 - 1;
        int curr = 0;
        temp = head;
        while(curr < mid) curr++, temp = temp->next;
        if(temp->next)
        temp->next = temp->next->next;
        // else temp->next = nullptr;
        if(mid < 0) head = head->next;
        return head;
    }
};