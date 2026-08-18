class segtree{
    public:
    vector<int> segarray;
    segtree(int n){
        segarray.resize(4*n , 0);
    }
    void build(int ind , int l , int r , vector<int>&vec){
        if(l == r){
            segarray[ind] = l;
            return;
        }
        int mid = l + (r-l)/2;
        build(2*ind+1 , l , mid , vec);
        build(2*ind+2 , mid+1 , r , vec);
        int le = segarray[2*ind+1];
        int ri = segarray[2*ind+2];
        if(vec[le] >= vec[ri]) segarray[ind] = le;
        else segarray[ind] = ri;
    }
    int query(int ind , int l , int r , int st , int en,vector<int>&vec ){
        if(l > en or r < st) return INT_MIN;
        if(l >= st and r <= en) return segarray[ind];
        int mid = l + (r-l)/2;
        int le = query(2*ind+1, l , mid , st , en, vec);
        int ri = query(2*ind+2 , mid+1 , r , st ,en, vec);
        int leftval = ( le != INT_MIN)? vec[le] : INT_MIN;
        int rightval = (ri != INT_MIN)? vec[ri] : INT_MIN;
        if(leftval >= rightval) return le;
        else return ri;
    }
};
class Solution {
public:
    int n;
    int check(int l, int r , segtree & seg, vector<int> &vec, int &maxi){
        while(l < r){
            int mid = l + (r-l)/2;
            int a = seg.query(0 , 0 , n-1, l , mid, vec);
            if(vec[a] > maxi){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        if(vec[l] > maxi)
            return l;

        return -1;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& que) {
         n = heights.size();
        segtree seg(n);
        seg.build(0 , 0 , n-1 , heights);
        vector<int> ans;
        for(auto x : que){
            int a = x[0] , b = x[1];
            if(a > b) swap(a , b);
            if(heights[b] > heights[a]){
                ans.push_back(b);
                continue;
            }
            if(a == b) {
                ans.push_back(a);
                continue;
            }
            int maxi = max(heights[a] , heights[b]);
            if(heights[a] == heights[b]) b++;
            int aa = check(b, n-1 , seg , heights, maxi);
            ans.push_back(aa);
        }
        return ans;
    }
};