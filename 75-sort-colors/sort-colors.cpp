class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0 = 0, n1 = 0, n2 = 0;
        for(int i : nums) {
            if(i == 0) n0++;
            if(i == 1) n1++;
            if(i==2) n2++;
        }
        for(int i=0;i<nums.size();i++) {
            if(n0) {
                nums[i]=0;
                n0--;
            }
            else if(n1) {
                nums[i] = 1;
                n1--;
            }
            else if(n2) {
                nums[i] = 2;
                n2--;
            }
        }
        
    }
};