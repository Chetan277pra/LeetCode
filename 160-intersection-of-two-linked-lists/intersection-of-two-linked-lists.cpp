/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ca = 0 , cb = 0;
        ListNode* a  = headA , *b = headB;
        while(a ) ca++ , a = a->next;
        while(b ) cb++ , b = b-> next;
        a = headA , b = headB;
        if(ca > cb){
            while(ca-cb > 0) ca--, a = a->next;
        }
        else while((cb - ca)) cb-- , b = b->next;
        while(a and b){
            if(a == b) return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};