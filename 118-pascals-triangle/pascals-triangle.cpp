class Solution {
public:
    vector<int> row(int n) {
        vector<int> res;
        int temp = 1;
        for(int i = 0; i < n; i++) {
            res.push_back(temp);

            temp*=(n-i-1);
            temp/=(i+1);

        }

        return res;
    }
    vector<vector<int>> generate(int n) {
        // 2nd variation
        vector<vector<int>> res;
        for(int i = 1; i <= n; i++) {
            res.push_back(row(i));
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