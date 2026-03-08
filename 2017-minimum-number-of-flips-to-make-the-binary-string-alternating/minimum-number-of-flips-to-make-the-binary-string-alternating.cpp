class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        string t = s + s;

        int op0 = 0, op1 = 0;

        for (int i = 0; i < n; i++) {
            if (t[i] != (i % 2 ? '1' : '0'))
                op0++;
            if (t[i] != (i % 2 ? '0' : '1'))
                op1++;
        }

        int ans = min(op0, op1);

        for (int i = n; i < 2 * n; i++) {

            if (t[i - n] != ((i - n) % 2 ? '1' : '0'))
                op0--;
            if (t[i - n] != ((i - n) % 2 ? '0' : '1'))
                op1--;

            if (t[i] != (i % 2 ? '1' : '0'))
                op0++;
            if (t[i] != (i % 2 ? '0' : '1'))
                op1++;

            ans = min(ans, min(op0, op1));
        }

        return ans;
    }
};
