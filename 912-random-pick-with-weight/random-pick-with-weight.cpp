class Solution {
public:
    vector<int> prefix;
    int total;
    Solution(vector<int>& w) {
        total = 0;
        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }
    int pickIndex() {
        int x = rand() % total + 1;
        int index = lower_bound(prefix.begin(), prefix.end(), x)
                    - prefix.begin();
        return index;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */