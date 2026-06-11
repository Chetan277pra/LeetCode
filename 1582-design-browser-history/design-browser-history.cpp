class BrowserHistory {
public:
    class Node{
        public:
        string val;
        Node* prev, *next;
        Node(string data){
            val = data;
            prev = next = NULL;
        }
    };
    Node *head, *temp;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        temp = head;
    }
    
    void visit(string url) {
        Node * tt = new Node(url);
        temp->next = tt;
        tt->prev = temp;
        temp = temp->next;
    }
    
    string back(int steps) {
        while(steps > 0 and temp->prev){
            steps--;
            temp = temp->prev;
        }
        return temp->val;
    }
    
    string forward(int steps) {
        while(steps > 0 and temp->next){
            steps--;
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */