class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odCnt = 0;


        int cur = 0;
        int cnt = 0;

        int newCnt = 0;
        int odCur = 1;

        for(int i: nums) {
            if(i&1) odCnt++;

            if((cur&1) && !(i&1)) {
                cur = i;
                cnt++;
            }
            else if(!(cur&1) && (i&1)) {
                cur = i;
                cnt++;
            }

            if((odCur&1) && !(i&1)) {
                odCur = i;
                newCnt++;
            }
            else if(!(odCur&1) && (i&1)) {
                odCur = i;
                newCnt++;
            }
        }

        
        int evCnt = n - odCnt;


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