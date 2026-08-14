class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int cnt[26] = {};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            // If a character occurs more than twice,
            // shrink the window from the left.
            while (cnt[s[right] - 'a'] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};