class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> newmatrix = matrix;

        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                newmatrix[j][m - i -1] = matrix[i][j];
            }
        }

        matrix = newmatrix;
    }
};