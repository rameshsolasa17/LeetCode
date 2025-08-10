class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> mp;
        while(n) {
            mp[n%10]++;
            n/=10;
        }

        for(int i = 0; i <= 30; i++) {
            long long temp = 1<<i;
            unordered_map<int, int> temp_mp;
            while(temp) {
                temp_mp[temp%10]++;
                temp/=10;
            }
            int f = 0;

            for(auto it: mp) {
                if(it.second != temp_mp[it.first]) {
                    f=1;
                    break;
                }
            }

            for(auto it: temp_mp) {
                if(it.second != mp[it.first]) {
                    f=1;
                    break;
                }
            }

            if(f == 0) return true;
        }

        return false;
    }
};