class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin() , arr1.end());
        sort(arr2.begin() , arr2.end());
        int count = 0;
        int n = arr1.size();
        for(int i = 0; i < n; i++){
            auto it = upper_bound(arr2.begin() , arr2.end() , arr1[i]);
            bool ok = true;
            if(it != arr2.end()) {
                if(*it - arr1[i] <= d) ok = false; 
            }
            if(!ok) continue;
            if(it != arr2.begin()){
                if(arr1[i] - *prev(it) <= d) ok = false;
            }
            if(!ok) continue;
            count++;
        }
        return count;
    }
};