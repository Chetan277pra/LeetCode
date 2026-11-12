class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int fsize=1,lsize=1;
        int temp=1;
        int ma=0;
        for(int i=0;i<n-1;i++)
        {
            ma=nums[i+1];
            if(nums[i]<ma)
            {
                temp++;
                if(temp>fsize)
                fsize=temp;
            }
            else
            temp=1;
        }
        temp=1;
        for(int i=0;i<n-1;i++)
        {
            ma=nums[i+1];
            if(nums[i]>ma)
            {
                temp++;
                if(temp>lsize)
                lsize=temp;
            }
            else
            temp=1;
        }
        return max(fsize,lsize);
    }
};