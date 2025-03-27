class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp, cmp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ele, cur = 0;

        for(int i = 0; i < n; i++) {
            if(cur == 0) {
                ele = nums[i];
            }
            else {
                int curSize = i;
                int remSize = n-curSize;

                int curNum = cmp[ele];
                int remNum = mp[ele] - cmp[ele];

                if(remNum*2 > remSize && curNum*2 > curSize) {
                    cout<<remSize<<' '<<remNum<<' ';
                    cout<<curSize<<' '<<curNum;
                    return i-1;
                }
            }

            cmp[nums[i]]++;
            if(ele == nums[i]) cur++;
            else cur--;
        }
        return -1;
    }
};

// 1127
//7769
// 318 ladywell  rd fri 75034