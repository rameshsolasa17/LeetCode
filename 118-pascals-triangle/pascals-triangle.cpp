class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        for(int i = 1; i <= n; i++) {
            res[i-1].resize(i);
            res[i-1][0] = 1;
            res[i-1][i-1] = 1;

            for(int j = 1; j < i-1; j++) {
                res[i-1][j] = res[i-2][j-1] + res[i-2][j];
            }
        }
        return res;
    }
};

/*
    TC = O(n^2)
    SC = O(n^2)
*/