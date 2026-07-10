class Solution {
public:
    bool check(string &a, string &b) {
        if (a.size() != b.size())
            return false;

        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1)
                    return false;
            }
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        unordered_map<string, vector<string>> graph;
        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord must exist
        if (!words.count(endWord))
            return 0;

        // Build graph among all words in wordList
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // Connect beginWord to all possible neighbors
        for (int i = 0; i < n; i++) {
            if (check(beginWord, wordList[i])) {
                graph[beginWord].push_back(wordList[i]);
            }
        }

        // BFS
        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({beginWord, 1});
        vis.insert(beginWord);

        while (!q.empty()) {

            auto [word, dist] = q.front();
            q.pop();

            if (word == endWord)
                return dist;

            for (auto &next : graph[word]) {
                if (!vis.count(next)) {
                    vis.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }

        return 0;
    }
};