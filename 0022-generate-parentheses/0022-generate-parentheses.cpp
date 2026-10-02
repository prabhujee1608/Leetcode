class Solution {
public:
    void backtrack(vector<string>& ans, string& curr, int open, int close, int n) {
        // We have used all 2*n parentheses
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            curr.push_back('(');
            backtrack(ans, curr, open + 1, close, n);
            curr.pop_back();
        }

        // Add ')' only if there is an unmatched '('
        if (close < open) {
            curr.push_back(')');
            backtrack(ans, curr, open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        backtrack(ans, curr, 0, 0, n);

        return ans;
    }
};
