class Solution {
public:
    //entire tree
    //entire row
    //single element
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 2; i <= numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j < i-1; j++) {
                temp.push_back(res[i-2][j-1] + res[i-2][j]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};