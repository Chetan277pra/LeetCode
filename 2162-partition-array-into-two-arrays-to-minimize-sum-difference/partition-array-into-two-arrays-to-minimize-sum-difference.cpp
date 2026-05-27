class Solution {
public:
    int n;
    unordered_map<int,vector<int>>ll,rr;
    void rec(vector<int>&nums,vector<vector<int>>&vec,int st,int end){
        int len=end-st;
        for(int mask=0;mask<(1<<len);mask++){

            // vector<int>temp;
            int sum=0;
            for(int i=st;i<end;i++){
                if(mask&(1<<(i-st))){
                    // temp.push_back(nums[i]);
                    sum+=nums[i];
                }
            }
            // vec.push_back(temp);
            ll[__builtin_popcount(mask)].push_back(sum);

        }
    }
    void rec2(vector<int>&nums,vector<vector<int>>&vec,int st,int end){
        int len=end-st;
        for(int mask=0;mask<(1<<len);mask++){

            vector<int>temp;
            int sum=0;
            for(int i=st;i<end;i++){
                if(mask&(1<<(i-st))){
                    // temp.push_back(nums[i]);
                    sum+=nums[i];
                }
            }
            // vec.push_back(temp);
            rr[__builtin_popcount(mask)].push_back(sum);
            
        }

    }
    int minimumDifference(vector<int>& nums) {

        n=nums.size();
        vector<vector<int>>left,right;

        rec(nums,left,0,n/2);
        rec2(nums,right,n/2,n);

    
       
        for(auto &a:rr){
            sort(a.second.begin(),a.second.end());
        }
        int ans=INT_MAX;
        int tot=accumulate(nums.begin(),nums.end(),0);
        for(auto &x:ll){

            int leftCount = x.first;
            int needCount = n/2-leftCount;
            for(int leftSum:x.second){
                int target=tot/2-leftSum;
                // auto &vec=rr[needCount];
                auto it=lower_bound(rr[needCount].begin(),rr[needCount].end(),target);
                if(it!=rr[needCount].end()){
                     ans=min(ans,abs(2*(leftSum+*it)-tot));
                }
                if(it!=rr[needCount].begin()){
                    --it;
                    
                    ans=min(ans,abs(2*(leftSum+*it)-tot));
                }
            }
        }
        return ans;
    }
};