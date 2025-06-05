class Solution {
public:
    void fun(int i, int t, vector<int> temp, vector<int>& nums, int k, vector<vector<int>>& res, int prev) {
        if(t == k) {
            res.push_back(temp);
            return ;
        }

       

        if(i == nums.size()) return;

         if(nums[i] == prev) {
            fun(i+1, t, temp, nums, k, res, nums[i]);
            return ;
        } 
        
        if(t > k) return ;

        fun(i+1, t, temp, nums, k, res, nums[i]);
        temp.push_back(nums[i]);
        t+=nums[i];
        // fun(i+1, t, temp, nums, k, res);
        fun(i+1, t, temp, nums, k, res, prev);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        fun(0, 0, temp, nums, k, res, -1);
        return res;
    }
};