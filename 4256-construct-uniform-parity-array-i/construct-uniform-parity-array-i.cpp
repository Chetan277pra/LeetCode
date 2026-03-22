class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        for(auto a : nums1) if(a%2) odd++;
        bool evenans = true , oddans = true;
        // even bna
        for(auto a : nums1){
            if(a%2 == 0 or odd > 1) continue;
            evenans = false;
            break;
        }
        // odd bna
        for(auto a : nums1){
            if(a%2 == 1 or odd > 0) continue;
            oddans = false;
            break;
        }
        return evenans or oddans;
    }
};