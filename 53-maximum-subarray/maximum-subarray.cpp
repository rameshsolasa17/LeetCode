class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN, cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(cur < nums[i]) cur = nums[i];
            res=max(res, cur);
        }
        return res;
    }
};