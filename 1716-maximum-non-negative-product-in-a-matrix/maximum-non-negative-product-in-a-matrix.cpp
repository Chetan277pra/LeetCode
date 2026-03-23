class Solution {
    int m, n;
    const int mod = 1e9 + 7;

    // memo[row][col] = {maxProduct, minProduct}
    vector<vector<pair<long long, long long>>> memo;
    vector<vector<bool>> vis;

    pair<long long, long long> rec(vector<vector<int>>& grid, int row,
                                   int col) {

        // Base case
        if (row == m - 1 && col == n - 1) {
            return {grid[row][col], grid[row][col]};
        }

        if (vis[row][col])
            return memo[row][col];

        long long cur = grid[row][col];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // Move Down
        if (row + 1 < m) {
            auto [downMax, downMin] = rec(grid, row + 1, col);

            maxi = max(maxi, max(cur * downMax, cur * downMin));
            mini = min(mini, min(cur * downMax, cur * downMin));
        }

        // Move Right
        if (col + 1 < n) {
            auto [rightMax, rightMin] = rec(grid, row, col + 1);

            maxi = max(maxi, max(cur * rightMax, cur * rightMin));
            mini = min(mini, min(cur * rightMax, cur * rightMin));
        }

        vis[row][col] = true;
        return memo[row][col] = {maxi, mini};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<pair<long long, long long>>(n));
        vis.assign(m, vector<bool>(n, false));

        auto [maxProd, minProd] = rec(grid, 0, 0);

        if (maxProd < 0)
            return -1;
        return maxProd % mod;
    }
};
