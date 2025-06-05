class Solution {
public:
    void fun(int i, int t, vector<int> temp, vector<int>& nums, int k, vector<vector<int>>& res) {
        if(t == k) {
            res.push_back(temp);
            return ;
        }

        if(i == nums.size()) return;
        if(t+nums[i] <=  k) {
            temp.push_back(nums[i]);
            t+=nums[i];
            fun(i, t, temp, nums, k, res);
            t-=nums[i];
            temp.pop_back();
        }

        
        

        fun(i+1, t, temp, nums, k, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        fun(0, 0, temp, nums, k, res);
        return res;
    }
};