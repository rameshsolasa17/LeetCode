class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0, cur = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            cur = min(cur, prices[i]);
            maxp = max(maxp, prices[i] - cur);
        }
        return maxp;
    }
};