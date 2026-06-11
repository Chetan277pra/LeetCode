/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    void rec(Node* &head){
        if(!head) return;

        while(head){
            if(!head->next and !head->child) return;
            if(!head->child){ head = head->next; continue;}
            Node* tt = head->next;
            Node* last = head->child;
            // cout << tt->val<<" ";
            head->next = last;
            last->prev = head;
            head->child = nullptr;
            rec(last);
            last->next = tt;
            if(tt)
            tt->prev = last;
            head = last;
            // cout << endl;
        }

    }
public:
    Node* flatten(Node* head) {
        Node* tt = head;
        rec(tt);
        return head;
    }
};