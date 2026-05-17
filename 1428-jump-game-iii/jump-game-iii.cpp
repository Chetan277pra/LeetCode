class Solution {
public:
    int n;
    bool rec(vector<int>& arr, int ind, vector<bool> &vis){
        if(ind >= n or ind < 0) return false;
        if(arr[ind] == 0) return true;
        // aage
        vis[ind] = true;
        // cout<<(ind + arr[ind])<<" "<<(ind - arr[ind])<<endl;
        bool aage = false;
        if((ind + arr[ind]) < n and   !vis[ind + arr[ind]])
         aage = rec(arr , ind + arr[ind] , vis);
        bool piche = false;
        if((ind - arr[ind]) >= 0 and   !vis[ind - arr[ind]])
         piche = rec(arr , ind - arr[ind] , vis);
        return aage or piche;
    }
    bool canReach(vector<int>& arr, int start) {
        int goal = -1;
        n = arr.size();
        // for(int i = 0; i < n; i++){ if(arr[i] == 0) {goal = i; break;}}
        // if(goal == -1) return false;
        vector<bool> vis(n , false);
        // cout<<goal<<endl;
        return rec(arr , start , vis);
    }
};