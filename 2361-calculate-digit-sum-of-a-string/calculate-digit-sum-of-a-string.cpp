class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string temp = "";
            int t = 0;
            int n = s.size();
            int i = 0;
            while(i < n){
                t += s[i]-'0';
                // cout << t << " " << i<<endl;
                if( (i+1)%k == 0){
                    temp += to_string(t);
                    t = 0;
                    // cout<<"here "<<t<<endl;
                }
                i++;
            }
            if(n%k != 0) temp += to_string(t);
            s = temp;
            // cout << s<< endl;
        }
        return s;
    }
};