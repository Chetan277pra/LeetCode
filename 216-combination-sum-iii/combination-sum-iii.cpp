class Solution {
public:
    vector<vector<int>> ans;
    void rec(int k , int n, int currsum , int ele , vector<int> &temp, int ind){
        if(ele == k) {
            if(currsum == n)
            ans.push_back(temp);

            return;
        }
        for(int i = ind+1; i < 10; i++){
            // cout << currsum << " " << ele << " " << ind<<endl;
            // for(auto a : temp) cout << a << " ";
            cout << endl << endl;
            temp.push_back(i);
            rec(k , n , currsum+i, ele+1 , temp , i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        rec(k , n, 0 , 0 , temp , 0);
        return ans;
    }
};