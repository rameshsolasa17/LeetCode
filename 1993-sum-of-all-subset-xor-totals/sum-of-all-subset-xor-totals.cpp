class Solution {
public:
    void fun(int i, int& temp, vector<int>& res, vector<int> &nums) {
        if(i == nums.size()) {
            res.push_back(temp);
            return ;
        }
        temp ^= nums[i];
        fun(i+1, temp, res, nums);
        temp ^= nums[i];
        fun(i+1, temp, res, nums);
        return ;
    }
    int subsetXORSum(vector<int>& nums) {
        int temp = 0;
        vector<int> res;
        fun(0, temp, res, nums);
        int t = 0;
        for(int i: res) t+=i;
        return t;
    }
};