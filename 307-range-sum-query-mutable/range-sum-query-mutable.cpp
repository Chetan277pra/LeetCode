
class NumArray {
public:
    vector<int> segarray , vec;
    int n;
    void build(int ind , int l , int r , vector<int>&vec){
        if(l == r){
            // cout<<ind << " " << l <<endl;
            segarray[ind] = vec[l];
            return;
        }
        int mid = l + (r - l)/2;
        // cout << ind << "  " <<l <<" " << mid<<" " << r << endl;
        build(2*ind+1 , l , mid , vec);
        build(2*ind+2 , mid+1 , r , vec);
        segarray[ind] = segarray[2*ind+1] + segarray[2*ind+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        vec = nums;
        segarray.resize(4*n , 0);
        // cout << n<<" " << vec.size() << "  " << segarray.size();
        build(0 , 0 , n-1 , vec);
    }

    void updatearray(int ind , int l , int r , int index,int val){

        if(l > index  or r < index) return;

        if(l == r and l == index){
            segarray[ind] = val;
            return;
        }
        int mid = l + (r - l)/2;
        updatearray(2*ind+1 , l , mid , index , val);
        updatearray(2*ind+2 , mid+1 , r , index , val);
        segarray[ind] = segarray[2*ind+1] + segarray[2*ind+2];
    }
    
    void update(int index, int val) {
        updatearray(0,0,n-1,index,val);
    }
    int query(int ind , int l , int r , int st , int en ){
        if(l > en or r < st) return 0;
        if(l >= st and r <= en) return segarray[ind];
        int mid = l + (r - l)/2;
        return query(2*ind+1 , l , mid , st , en) + query(2*ind+2 , mid+1 , r , st , en);
    }
    int sumRange(int left, int right) {
        return query(0 , 0 , n-1 , left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */