class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        int x = 0, y = 0;
        int dir = 0;

        set<pair<int,int>> obstacles;
        for (auto &o : obs) {
            obstacles.insert({o[0], o[1]});
        }
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int maxDist = 0;

        for (int cmd : com) {
            if (cmd == -1) {
                dir = (dir + 1) % 4; // turn right
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4; // turn left
            }
            else {
                while (cmd--) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (obstacles.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};