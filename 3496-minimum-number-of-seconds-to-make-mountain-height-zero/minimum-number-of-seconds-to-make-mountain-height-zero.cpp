class Solution {
public:
    long long eqn(long long a, long long b, long long c) {
        double val = (-b + sqrt((double)b * b - 4 * a * c)) / (2 * a);
        return (long long)val;
    }

    bool check(vector<int>& work, long long sec, int mount) {

        long long ans = 0;

        for (auto a : work) {
            long long temp = sec / a;
            ans += eqn(1, 1, -2*temp);

            if (ans >= mount)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mount, vector<int>& work) {

        long long l = 1, r = 1e18;

        while (l < r) {

            long long mid = l + (r - l) / 2;

            if (check(work, mid, mount))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
