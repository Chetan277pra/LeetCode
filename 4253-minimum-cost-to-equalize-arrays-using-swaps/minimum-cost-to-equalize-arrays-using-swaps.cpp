class Solution {
public:
    int minCost(vector<int>& aa, vector<int>& bb) {
        map<int, int> mapa, mapb;
        for (auto a : aa)
            mapa[a]++;
        for (auto a : bb)
            mapb[a]++;
        int ans = 0;
        set<int> vis;
        set<int> nums1(aa.begin(), aa.end());
        for (auto a : nums1) {
            if (mapa[a] == mapb[a])
                continue;
            if (abs(mapa[a] - mapb[a]) % 2)
                return -1;
            int diff = abs(mapa[a] - mapb[a]) / 2;
            ans += diff;
            vis.insert(a);
            // for (auto a : vis)
            //     cout << a << " ";
            // cout << endl;
            // cout << " ans : " << ans;
            // cout << endl;
        }
        set<int> nums2(bb.begin(), bb.end());
        for (auto a : nums2) {
            if (mapa[a] == mapb[a])
                continue;
            if (abs(mapa[a] - mapb[a]) % 2)
                return -1;
            int diff = abs(mapa[a] - mapb[a]) / 2;
            if (!vis.count(a))
            ans += diff;
            // for (auto a : vis)
            //     cout << a << " ";
            // cout << endl;
            // cout << " ans : " << ans;
            // cout << endl;
        }
        return ans / 2;
    }
};