class Solution {
public:

    bool dfs(int node, int currColor, vector<int>& color,
             vector<vector<int>>& graph) {

        color[node] = currColor;

        for (int neigh : graph[node]) {

            // Not colored yet
            if (color[neigh] == -1) {

                if (!dfs(neigh, 1 - currColor, color, graph))
                    return false;
            }

            // Already colored
            else if (color[neigh] == currColor) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        // Graph may be disconnected
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }

        return true;
    }
};