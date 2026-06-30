class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            count += (start & 1 << i) != (goal & 1 << i);
        }
        return count;
    }
};
