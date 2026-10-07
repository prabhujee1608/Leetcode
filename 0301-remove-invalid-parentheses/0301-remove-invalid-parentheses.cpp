class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int removeLeft, int removeRight) {

        // We have removed all required parentheses
        if (removeLeft == 0 && removeRight == 0) {

            int balance = 0;

            // Check whether string is valid
            for (char c : s) {

                if (c == '(')
                    balance++;

                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        // Try removing parentheses
        for (int i = start; i < s.size(); i++) {

            // Avoid duplicate results
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (removeLeft > 0 && s[i] == '(') {

                string temp = s.substr(0, i) + s.substr(i + 1);

                solve(temp, i, removeLeft - 1, removeRight);
            }

            // Remove ')'
            if (removeRight > 0 && s[i] == ')') {

                string temp = s.substr(0, i) + s.substr(i + 1);

                solve(temp, i, removeLeft, removeRight - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        ans.clear();

        int removeLeft = 0;
        int removeRight = 0;

        // Find minimum number of '(' and ')' to remove
        for (char c : s) {

            if (c == '(') {
                removeLeft++;
            }

            else if (c == ')') {

                if (removeLeft > 0)
                    removeLeft--;
                else
                    removeRight++;
            }
        }

        // Start recursion
        solve(s, 0, removeLeft, removeRight);

        // Remove duplicates
        sort(ans.begin(), ans.end());

        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};