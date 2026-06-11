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
public:
    Node* flatten(Node*&head) {
        Node* temp = head;
        while(temp){
            if(!temp->child) {temp = temp->next; continue;}
            Node* tt = temp->next;
            Node* cc = temp->child;
            temp->child = nullptr;
            temp->next = cc;
            cc->prev = temp;
            while(cc->next) cc = cc->next;
            cc->next = tt;
            if(tt)
            tt->prev = cc;
            temp = temp->next;
        }
        return head;
    }
};