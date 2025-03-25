class Solution {
public:
    bool mergeIntervals(vector<vector<int>> i) {
        sort(i.begin(), i.end());
        int temp = i[0][1];
        int res = 1;
        int n = i.size();

        for(int j = 1; j < n; j++) {
            if(temp <= i[j][0]) {
                res++;
                if(res>=3) return true;
                temp = i[j][1];
            }
            else {
                temp = max(temp, i[j][1]);
            }
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        vector<vector<int>> x, y;
        for(auto it: rect) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }
        if(mergeIntervals(x)) return true;
        if(mergeIntervals(y)) return true;
        return false;
    }
};