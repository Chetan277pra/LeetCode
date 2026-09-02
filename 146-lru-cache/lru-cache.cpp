class LRUCache {
public:
    class node {
    public:
        int key;
        node* prev;
        node* next;
        node(int k) {
            key = k;
            prev = next = nullptr;
        }
    };
    int size;
    node* head;
    node* tail;

    map<int, pair<node*, int>> mpp;

    LRUCache(int cap) {
        size = cap;
        head = tail = nullptr;
    }

    void moving_front(node* curr) {

        // Already at head
        if (curr == head)
            return;

        // If curr is tail
        if (curr == tail) {
            tail = curr->prev;
            tail->next = nullptr;
        }
        else {
            // Remove curr from middle
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        // Put curr at front
        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;
    }

    int get(int key) {

        if (mpp.find(key) == mpp.end())   return -1;
        node* curr = mpp[key].first;
        moving_front(curr);
        return mpp[key].second;
    }

    void put(int key, int value) {

        // Key already exists
        if (mpp.find(key) != mpp.end()) {

            node* curr = mpp[key].first;

            // Update value
            mpp[key].second = value;

            // Mark as recently used
            moving_front(curr);

            return;
        }

        // Create new node
        node* temp = new node(key);

        // Insert at front
        temp->next = head;

        if (head != nullptr) {
            head->prev = temp;
        }
        else {
            // First node
            tail = temp;
        }

        head = temp;

        mpp[key] = {temp, value};

        // Capacity exceeded
        if (mpp.size() > size) {

            node* last = tail;

            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                // Cache became empty
                head = nullptr;
            }

            mpp.erase(last->key);

            delete last;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */