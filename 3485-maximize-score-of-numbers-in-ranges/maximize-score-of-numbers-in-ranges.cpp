class Solution {
public:
    bool check(vector<int>& start, int d, int res) {
        long long last = start[0];
        for(int i = 1; i < start.size(); i++) {
            long long  newlast = max(last + res, (long long )start[i]);
            last = newlast;
            if(newlast > start[i] + d) {
                return 0;
            }
        }
        return 1;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long  s = 0, e = start.back() - start.front() + d;
        //cout<<s<<e;
        long long  res = 0;
        while(s<=e) {
            long long m = (s+e)/2;
            if(check(start, d, m)) {
                s = m + 1;
                res = m;
            }
            else {
                e = m - 1;
            }
        }
        return res;
    }
};