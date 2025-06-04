class Solution {
public:
    void fun(int i, vector<int>& nums, vector<int> temp, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(temp);
            return ;
        }

        fun(i+1, nums, temp, res);
        temp.push_back(nums[i]);
        fun(i+1, nums, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        fun(0, nums, temp, res);
        return res;
    }
};