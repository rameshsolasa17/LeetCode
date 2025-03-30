class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for(int i = 0; i<n; i++) {
            mp[s[i]]++;
        }
        vector<int> res;
        int cnt = 0;
        int l = 0;
        for(int i = 0; i<n;i++) {
            if(mp1[s[i]]) {}
            else {
                cnt++;
                mp1[s[i]]++;
            }
            mp[s[i]]--;
            l++;
            if(mp[s[i]] == 0) cnt--;

            if(cnt == 0) {
                res.push_back(l);
                l = 0;
            }

        }
        return res;
    }
};