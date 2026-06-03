class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;
        for(int i = 0; i < n; i++){
            if(s[i] == goal[0]){
                bool ok = true;
                for(int j = 0; j < n; j++){
                    if(s[(i+j)%n] != goal[j]){
                        ok = false; break;
                    }
                }
                if(ok) return true;
            }
        }
        return false;
    }
};