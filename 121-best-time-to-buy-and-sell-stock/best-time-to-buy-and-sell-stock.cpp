class Solution {
public:
    int maxProfit(vector<int>& p) {
        int cur = p[0];
        int res = 0;
        for(int i = 0; i < p.size(); i++) {
            if(cur < p[i]) {
                res = max(res, p[i] - cur);
            }
            else {
                cur = p[i];
            }
        }
        return res;
    }
};