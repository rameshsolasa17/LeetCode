class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        for(int i: nums) {
            if(i < k) return -1;
            else if(i > k && !mp[i]) {
                mp[i] = 1;
                res++;
            }
        }
        return res;
    }
};