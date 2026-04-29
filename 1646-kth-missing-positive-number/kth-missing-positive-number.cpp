class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int l = 0;
        int r = arr.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            int kitne = arr[mid] - mid -1;
            if(kitne < k) l = mid + 1;
            else r = mid;
        }
        cout<<l<<" "<<arr[l];
        int kitne = arr[l] - l - 1;
        if(l == arr.size()-1  and kitne < k) return arr[l] + k - kitne;
        return arr[l] + k - kitne -1;
    }
};