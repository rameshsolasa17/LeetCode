class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long res=0LL, temp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    temp=(nums[i] - nums[j]);
                    temp*=nums[k];
                    res=max(res, temp);
                }
            }
        }
        return res;
    }
};