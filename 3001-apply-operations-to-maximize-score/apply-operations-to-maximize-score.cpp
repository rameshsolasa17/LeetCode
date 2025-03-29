class Solution {
public:
    int mod = 1e9+7;
    int primeFactors(int n) {
        int cnt = 0;

        if(n%2 == 0)  cnt++;
        while (n % 2 == 0) n/=2;

        for (int i = 3; i*i <= n; i = i + 2) {
            if(n%i == 0) cnt++;
            while (n % i == 0) n = n/i;
        } 
        
        if (n > 2) cnt++;

        return cnt;
    } 
    void nextGreater(vector<int>& nums, vector<int>& res) {
        int n = nums.size();

        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            if(st.empty()) res[i] = n;
            else res[i] = st.top();

            st.push(i);
        }
    }

    void prevGreater(vector<int>& nums, vector<int>& res) {
        int n = nums.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            if(st.empty()) res[i] = -1;
            else res[i] = st.top();

            st.push(i);
        }
    }


    long long fast_exp(long long x, int exp) {
        if (x == 0) return 0;
        if (exp == 0) return 1;
        long long a = (exp % 2 == 1) ? x : 1;
        return fast_exp(x * x % mod, exp / 2) * a % mod;
    }


    int maximumScore(vector<int>& nums, int k) {
        int res = 1;
        int mod = 1e9+7;
        int n = nums.size();
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++) {
            p[i] = primeFactors(nums[i]);
        }

        vector<int> r(n, -1), l(n, -1);
        nextGreater(p, r);
        prevGreater(p, l);
        
        vector<pair<int, int>> sortedNums;
        for(int i = 0; i < n; i++) {
            sortedNums.push_back({nums[i], i});
        }
        sort(sortedNums.rbegin(), sortedNums.rend());
        
        for(int i = 0; i < n; i++) {
            int ind = sortedNums[i].second;
            int num = sortedNums[i].first;
            int len = min((long long)(r[ind] - ind)*(ind - l[ind]), (long long) k);

            // res *= pow(num, len);
            k-=len;
            res=(res*fast_exp(num,len)%mod);
            if(k == 0) {
                break;
            }
        }
        return res;
    }
};

//KEY LEARNINGS
/*
    1) monotonic
    2) multiply in line 79
*/