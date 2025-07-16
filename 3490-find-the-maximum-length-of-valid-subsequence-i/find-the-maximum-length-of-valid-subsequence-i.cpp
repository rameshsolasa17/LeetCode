class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odCnt = 0;
        for(int i: nums) if(i&1) odCnt++;

        int evCnt = n - odCnt;

        int cur = 0;
        int cnt = 0;
        for(int i: nums) {
            if((cur&1) && !(i&1)) {
                cur = i;
                cnt++;
            }
            else if(!(cur&1) && (i&1)) {
                cur = i;
                cnt++;
            }
        }

        int newCnt = 0;
        cur = 1;
        for(int i: nums) {
            if((cur&1) && !(i&1)) {
                cur = i;
                newCnt++;
            }
            else if(!(cur&1) && (i&1)) {
                cur = i;
                newCnt++;
            }
        }

        return max({odCnt, evCnt, cnt, newCnt});


    }
};

/* 
two cases
0
even
odd

1
eve odd eve

*/