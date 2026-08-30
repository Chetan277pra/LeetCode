class Solution {
public:
    class segtree{
        public:
        vector<int> segarray;
        segtree(int n){
            segarray.resize(4*n , 0);
        }
        // void build(int ind , int l , int r){
        //     if(l == r){
        //         segarray[l] = 0;
        //         return;
        //     }
        //     int mid = l + (r - l)/2;
        //     build(2*ind+1 , l , mid );
        //     build(2 * ind+2 , mid+1 , r);
        //     segarray[ind] = segarray[2*ind+1] + segarray[2*ind+2];
        // }
        void update(int ind, int l , int r , int target){
            if(l == r){
                if(l == target) {
                    segarray[ind] = 1;
                    return;
                }
                else return;
            }
            int mid = l + (r - l)/2;
            if(mid >= target)
            update(2*ind+1 , l , mid , target);
            else 
            update(2*ind+2 , mid+1 , r , target);
            segarray[ind] = segarray[2*ind+1] + segarray[2*ind+2];
        }
        int query(int ind , int l , int r , int st , int en){
            if(l > en or r < st) return 0;
            if(l >= st and r  <= en) return segarray[ind];
            int mid = l + (r - l)/2;
            return query(2*ind+1 , l , mid , st , en) + query(2*ind+2 , mid+1 , r, st ,en);
        }
    };
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        segtree seg(n);
        long long ans = 0;
        map<int , int > mpp;
        for(int i = 0; i  < n; i++ ) mpp[nums2[i]] = i;
        // seg.build(0 , 0 , n-1 , )
        seg.update(0 , 0 , n-1 , mpp[nums1[0]]);
        for(int i = 1; i < n; i++){
            int pos = mpp[nums1[i]];
            int leftcommon = seg.query(0 , 0 , n-1 , 0 , pos-1);
            int leftun = i - leftcommon;
            int rightcommon = (n - 1 - pos) - leftun;
            ans += ((long long)leftcommon * (long long)rightcommon);
            seg.update(0 , 0 , n-1 , pos );
        }
        return ans;
    }
};