class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = m+n-1;
        m--; n--;
        cout<<m<<" "<<n<<" "<<right<<endl;
        while(n >= 0){
            if(m >= 0 and nums1[m] > nums2[n]) nums1[right--] = nums1[m--];
            else nums1[right--] = nums2[n--];
        }
    }
};