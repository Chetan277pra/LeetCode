class Solution {
public:
    class segtree{
        public:
        vector<int> segarray;
        segtree(int n){
            segarray.resize(4*n , 0);
        }
        void build(int ind , int l , int r , vector<int>&vec){
            if(l == r){
                segarray[ind] = vec[l];
                return;
            }
            int mid = l + (r - l)/2;
            build(2*ind+1 , l , mid , vec);
            build(2*ind+2 , mid+1 , r , vec);
            segarray[ind] = max(segarray[2*ind+1] , segarray[2*ind+2]);
        }
        int query(int ind , int l , int r, int target){
            if(segarray[ind] < target) return -1;
            if(l == r) {
                int temp = segarray[ind];
                segarray[ind] = 0;
                return temp;
            }
            int mid = l + (r - l)/2;
            int curr = -1;
            if(segarray[2*ind+1] >= target) 
                curr = query(2*ind+1 , l , mid , target);
            else if(segarray[2*ind+2] >= target)
                curr = query(2*ind+2 , mid+1 , r , target);
            segarray[ind] = max(segarray[2*ind+1] , segarray[2*ind+2]);
            return curr;
        }
    };
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segtree seg(n);
        seg.build(0 , 0 , n-1 , baskets);
        int ans;
        for(auto a : fruits){
            int curr = seg.query(0 , 0 , n-1 , a);
            ans += (curr == -1);
        }
        return ans;
    }
};