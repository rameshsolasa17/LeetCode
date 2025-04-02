class Solution {
public:
    long long fun(int i, vector<vector<int>>& q, vector<long long> &dp) {
        if(i >= q.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(q[i][0] + fun(i+q[i][1]+1, q, dp), fun(i+1, q, dp));
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, -1);
        return fun(0, q, dp);
    }
};