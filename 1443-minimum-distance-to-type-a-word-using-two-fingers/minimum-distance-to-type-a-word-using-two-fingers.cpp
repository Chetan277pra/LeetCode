#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    // Calculate Manhattan distance between two characters
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0; // Finger not used yet
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int rec(string &word, int ind, int f1, int f2) {
        if (ind == n) return 0;

        if (dp[ind][f1][f2] != -1)
            return dp[ind][f1][f2];

        int curr = word[ind] - 'A';

        // Option 1: Use first finger
        int useFirst = dist(f1, curr) + rec(word, ind + 1, curr, f2);

        // Option 2: Use second finger
        int useSecond = dist(f2, curr) + rec(word, ind + 1, f1, curr);

        return dp[ind][f1][f2] = min(useFirst, useSecond);
    }

    int minimumDistance(string word) {
        n = word.size();
        dp.assign(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return rec(word, 0, 26, 26); // दोनों fingers initially unused
    }
};