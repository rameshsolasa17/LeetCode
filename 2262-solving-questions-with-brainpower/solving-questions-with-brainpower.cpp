class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(q.size(), 0);
        for (int i = q.size() - 1; i >= 0; i--) {
            int index = i + q[i][1] + 1;
            if (index < q.size()) {
                dp[i] = dp[index] + q[i][0];
            } else {
                dp[i] = q[i][0];
            }
            if (i < q.size() - 1) {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
    }
};