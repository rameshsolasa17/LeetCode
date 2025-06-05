class Solution {
public:
    void fun(int i, int t, vector<int>& nums, vector<int> temp, vector<vector<int>>& res, int k, int n) {
        if(t == n && temp.size() == k) {
            res.push_back(temp);
            return ;
        }

        if(i == nums.size()) return ;

        fun(i+1, t, nums, temp, res, k, n);
        
        if(t < n && temp.size() < k) {
            t+=nums[i];
            temp.push_back(nums[i]);
            fun(i+1, t, nums, temp, res, k, n);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        vector<vector<int>> res;
        vector<int> temp;
        fun(0, 0, nums, temp, res, k, n);
        return res;
    }
};