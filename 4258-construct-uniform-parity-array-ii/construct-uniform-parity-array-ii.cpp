class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int odd = 0;
        for(auto a : nums1) if(a%2) {mini = min(mini , a); odd++;}
        // even bna
        bool evenans = true,  oddans = true;
        for(auto a : nums1){
            if(a%2 ==0 or (odd > 1 and a-1 >= mini) ) continue;
            evenans = false;
            break;
        }
        // odd bna
        for(auto a : nums1){
            // cout<<"odd ans"<<oddans<<" a : "<<a<<endl;
            if(a%2 == 1 or (odd > 0 and a-1 >= mini)) continue;
            oddans = false;
            break;
        }
        return oddans or evenans;
    }
};