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
        int count = 0;
        ListNode* temp = head;
        while(temp) count++, temp = temp->next;
        int mid = (count+1)/2;
        int curr= 0;
        temp = head;
        ListNode* prev = nullptr ;
        ListNode* nn = nullptr;
        while(curr < count){
            if(curr < mid) {
                curr++;
                temp = temp->next;
            }
            else{
                curr++;
                nn = temp->next;
                temp->next = prev;
                prev = temp;
                if(curr < count)
                temp = nn;
                // return true;
            }
            cout << curr << endl;
        }
        // return true;
        // cout << curr << " " << mid;
        // cout << temp->val;
        while(temp){
            if(head->val != temp->val) return false;
            temp = temp->next;
            head = head->next;
        }
        return true;
    }
};