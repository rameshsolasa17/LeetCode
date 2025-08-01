class Solution {
public:
    int cell(int x, int y) {
        int temp = 1;
        for(int i = 1; i <= y; i++) {
            temp*=(x-i+1);
            temp/=i;
        }

        return temp;
    }
    vector<vector<int>> generate(int n) {
        // 3rd variation
        vector<vector<int>> res;

        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j=0;j<=i;j++) {
                temp.push_back(cell(i, j));
            }
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