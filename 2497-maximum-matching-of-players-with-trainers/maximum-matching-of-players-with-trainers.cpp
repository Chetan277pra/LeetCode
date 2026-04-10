class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int n = p.size() , m = t.size();
        int i = 0, j = 0;
        while(i < n and j < m) {
            if(p[i] <= t[j])
            i++;
         j++;
        }
        return i;
    }
};