class Solution {
public:
    
    int ans = 0;
    void logic(vector<int> &arr, int l, int mid, int r){
        int left = l , right = mid+1;
        vector<int> temp;

        // ans function

        while(left <= mid and right <= r){
            if(arr[left] <= 2LL*arr[right] ) left++;
            else{
                ans += mid-left+1;
                right++;
            }
        }
        left = l , right = mid+1;
        while(left <= mid and right <= r){
            if(arr[left] <= arr[right] ) temp.push_back(arr[left++]);
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid) temp.push_back(arr[left++]);
        while(right <= r) temp.push_back(arr[right++]);
        // cout<<"arr is : ";
        // for(auto a : arr) cout<<a<<" ";
        // cout<<endl<<"vec is : ";
        // for(auto a : temp) cout<<a<<" ";
        // cout<<endl; 
        // cout<<" ans is "<<ans<<endl;
        for(int i = l; i <= r; i++) arr[i] = temp[i - l];
    }
    void merge(vector<int> &arr, int l , int r){
        if(l >= r) return;
        int mid = l + (r - l)/2;
        merge(arr , l , mid);
        merge(arr, mid+1 , r);
        logic(arr, l , mid, r);
    }


    int reversePairs(vector<int>& nums) {
        merge(nums , 0 , nums.size()-1);
        return ans;
    }
};