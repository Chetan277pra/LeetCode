class LFUCache {
public:
    int cap;
    struct info{
        int key , value , count;
    };
    map<int, list<info>> freq;
    map<int , list<info>::iterator> mpp;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        auto add = mpp[key];
        info inf = *add;
        freq[inf.count].erase(add);
        if (freq[inf.count].empty()) {
            freq.erase(inf.count);
        }
        freq[inf.count+1].push_front(info{inf.key, inf.value, inf.count + 1});
        mpp[key] = freq[inf.count+1].begin();
        return inf.value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(mpp.find(key) != mpp.end()){
            info up = *mpp[key];
            freq[up.count].erase(mpp[key]);
            if (freq[up.count].empty()) {
                freq.erase(up.count);
            }
            freq[up.count+1].push_front({key , value , up.count+1});
            mpp[key] = freq[up.count+1].begin();
            return;
        }
        if(mpp.size() == cap){

            auto freqIt = freq.begin();
            info toremove = freqIt->second.back();
            freqIt->second.pop_back();
            mpp.erase(toremove.key);
            if (freqIt->second.empty()) {
                freq.erase(freqIt);
            }
        }
    
        freq[1].push_front(info{key, value, 1});
        mpp[key] = freq[1].begin();
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */