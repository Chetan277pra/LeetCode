class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return 0;

        unordered_set<string> beginSet;
        unordered_set<string> endSet;

        beginSet.insert(beginWord);
        endSet.insert(endWord);

        dict.erase(beginWord);
        dict.erase(endWord);

        int len = 1;

        while (!beginSet.empty() && !endSet.empty()) {

            // Always expand the smaller frontier
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextLevel;

            for (string word : beginSet) {

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == original)
                            continue;

                        word[i] = ch;

                        // Searches meet
                        if (endSet.count(word))
                            return len + 1;

                        if (dict.count(word)) {
                            nextLevel.insert(word);
                            dict.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            beginSet = nextLevel;
            len++;
        }

        return 0;
    }
};