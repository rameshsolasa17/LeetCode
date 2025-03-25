class Solution {
public:
    int mergeIntervals(vector<vector<int>> i) {
        sort(i.begin(), i.end());
        vector<int> temp = i[0];
        int res = 1;
        int n = i.size();

        for(int j = 1; j < n; j++) {
            if(temp[1] <= i[j][0]) {
                res++;
                // cout<<temp[0]<<' '<<temp[1]<<'\n';
                temp = i[j];
            }
            else {
                temp[1] = max(temp[1], i[j][1]);
            }
        }
        return res;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        vector<vector<int>> x, y;
        for(auto it: rect) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }
        if(mergeIntervals(x) >= 3) return true;
        if(mergeIntervals(y) >= 3) return true;
        return false;
    }
};