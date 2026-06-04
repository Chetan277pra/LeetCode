class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            string temp = to_string(i);
            int n = temp.size();
            for(int i = 1; i < n-1; i++){
                if((temp[i-1] < temp[i] and temp[i] > temp[i+1])
                or(temp[i-1] > temp[i] and temp[i] < temp[i+1]) )
                ans++;
            }
        }
        return ans;
    }
};