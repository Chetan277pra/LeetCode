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
    ListNode* middleNode(ListNode* head) {
        int tot = 0;
        ListNode* temp = head;
        while(temp) {
            tot++;
            temp = temp->next;
        }
        int mid = (tot)/2;
        int curr = 0;
        while(curr < mid){
            curr++;
            head = head->next;
        }
        return head;
    }
};