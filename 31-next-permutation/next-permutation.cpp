class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i = n-1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                break;
            }
        }
        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return ;
        }

        i = i-1;

        for(int j = n-1; j >= 0; j--) {
            if(nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }

        sort(nums.begin() + i + 1, nums.end());
    }
};