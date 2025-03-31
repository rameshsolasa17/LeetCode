class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<int> v;
        int n = w.size();
        for(int i = 0; i < n-1; i++) {
            v.push_back(w[i] + w[i+1]);
        }
        sort(v.begin(), v.end());
        int k_ = k-1;
        int i = 0;
        long long mi = 0;
        while(k_ --) {
            mi += v[i++];
        }

        k_ = k-1;
        i = n-2;
        long long ma = 0;
        while(k_--) {
            ma+=v[i--];
        }

        return ma - mi;

    }
};