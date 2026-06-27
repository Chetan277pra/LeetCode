class Solution {
public:
    vector<string> ans;

    void dfs(string &num, int target, int index,
             long long currValue,
             long long prevOperand,
             string path) {

        // All digits are used
        if (index == num.size()) {
            if (currValue == target)
                ans.push_back(path);
            return;
        }

        long long currNum = 0;

        for (int i = index; i < num.size(); i++) {

            // Prevent numbers like 05, 00, 012
            if (i > index && num[index] == '0')
                break;

            currNum = currNum * 10 + (num[i] - '0');

            string currStr = num.substr(index, i - index + 1);

            // First number: don't put any operator before it
            if (index == 0) {
                dfs(num, target,
                    i + 1,
                    currNum,
                    currNum,
                    currStr);
            }
            else {

                // +
                dfs(num, target,
                    i + 1,
                    currValue + currNum,
                    currNum,
                    path + "+" + currStr);

                // -
                dfs(num, target,
                    i + 1,
                    currValue - currNum,
                    -currNum,
                    path + "-" + currStr);

                // *
                dfs(num, target,
                    i + 1,
                    currValue - prevOperand + prevOperand * currNum,
                    prevOperand * currNum,
                    path + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        dfs(num, target, 0, 0, 0, "");

        return ans;
    }
};