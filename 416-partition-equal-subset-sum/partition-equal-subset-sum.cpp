class Solution {
public:
    bool fun(int i, vector<int> nums, int sum, int cur, vector<vector<int>>& dp) {
        if(i == nums.size() || sum < cur) {
            return false;
        }

        if(sum == cur) return 1;

        if(dp[i][cur] != -1) return dp[i][cur]; 
        return dp[i][cur] =  fun(i+1, nums, sum, cur + nums[i], dp) || fun(i+1, nums, sum, cur, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums) {
            sum += i;
        }
        if(sum&1) return 0;

        sum/=2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return fun(0, nums, sum, 0, dp);
    }
}; 