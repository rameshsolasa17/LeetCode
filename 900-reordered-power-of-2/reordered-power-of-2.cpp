class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // unordered_map<int, int> mp;
        vector<int> mp;
        while(n) {
            mp.push_back(n%10);
            n/=10;
        }
        sort(mp.begin(), mp.end());

        for(int i = 0; i <= 30; i++) {
            long long temp = 1<<i;
            vector<int> temp_mp;
            while(temp) {
                temp_mp.push_back(temp%10);
                temp/=10;
            }

            sort(temp_mp.begin(), temp_mp.end());

            if(mp == temp_mp) return true;

        }

        return false;
    }
};