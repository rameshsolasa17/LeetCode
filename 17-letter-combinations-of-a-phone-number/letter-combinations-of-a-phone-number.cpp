class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> res = {""};
        vector<string> ans;
        map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        for(char d: digits) {
            for(char c: mp[d]) {
                for(string s: res) {
                    ans.push_back(s+c);
                }
            }
            res=ans;
            ans.clear();
        }
        return res;
    }
};