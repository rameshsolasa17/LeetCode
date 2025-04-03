class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);

        left[0] = nums[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], nums[i]);
        }

        // for(int i: left) {
        //     cout<<i<<' ';
        // }
        // cout<<'\n';

        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], nums[i]);
        }

        // for(int i: right) {
        //     cout<<i<<' ';
        // }
        // cout<<'\n';


        long long res = 0;
        for(int i = 1; i < n-1; i++) {
            long long temp = left[i] - nums[i];
            res = max(res, temp*right[i+1]);
            // cout<<res<<' ';
        }
        return res;
    }
};