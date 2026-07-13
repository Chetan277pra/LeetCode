class Solution {
public:
    int get(int n){
        int count = 0;
        while(n){
            count++;
            n /= 10;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        map<int , int> mpp;
        mpp[2] = 12;
        mpp[3] = 123;
        mpp[4] = 1234;
        mpp[5] = 12345;
        mpp[6] = 123456;
        mpp[7] = 1234567;
        mpp[8] = 12345678;
        mpp[9] = 123456789;
        vector<int> one = {0 , 1 , 11 , 111 , 1111, 11111 , 111111, 1111111, 11111111, 111111111};
        int l = get(low);
        int r = get(high);
        vector<int> ans;
        for(int i = l; i < r; i++){
            long long curr = mpp[i];
            for(int j = 0; j < 10-i; j++){
                // cout << curr <<"("<<j<<") ";
                if(curr >= low) ans.push_back(curr); 
                curr += one[i];
            }
            cout<<endl;
        }
        long long curr = mpp[r];
        for(int i = 0; i < 10-r; i++){
            if( curr >= low and curr <= high) ans.push_back(curr);
            curr += one[r];
        }
        return ans;
    }
};