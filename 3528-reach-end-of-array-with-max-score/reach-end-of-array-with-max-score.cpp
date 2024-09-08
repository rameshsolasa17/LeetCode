class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int last = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(last < nums[i]) {
                res += nums[i];
                last = nums[i];
            }
            else {
                res += last;
            }
        }
        return res;
    }
};