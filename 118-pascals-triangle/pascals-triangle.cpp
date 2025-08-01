class Solution {
public:
    vector<vector<int>> generate(int n) {
        // 1st variation
        vector<vector<int>> res;
        res.push_back({1});
        n-=1;

        for(int i = 1; i <= n; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j <= i-1; j++) {
                temp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            temp.push_back(1);

            res.push_back(temp);
        }

        return res;

    }
};



/*
Three variations,
1 -> Build entire pascal triangle
2 -> Build single row
3 -> return single element
*/