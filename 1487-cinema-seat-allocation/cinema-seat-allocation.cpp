class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        sort(res.begin() , res.end());
        int ans = 0;
        int last = 0;
        int i = 0;
        int m = res.size();
        while(i < m){
            int curr = res[i][0];
            int j = i;
            vector<int> temp;
            while(j < m and res[j][0] == curr){
                temp.push_back(res[j][1]);
                j++;
            }
            i = j;
            ans += (curr-last-1)*2;
            last = curr;
            // cout << i << " " <<last<<" " << j<< " ans : "<< ans<<endl;
            bool f = true , s = true , t= true;
            for(auto a : temp){
                if(a > 1 and a < 6) f = false;
                if(a > 3 and a < 8) s = false;
                if(a > 5 and a < 10) t = false;
            }
            int count = f || s || t;
            count = max(count , f + t);
            ans += count;
            // cout << ans << "\n";
        }
        ans += (n-last)*2;
        return ans;
    }
};