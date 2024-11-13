class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    if(j == 0) col = 1;
                    else {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j > 0; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            if(col == 1) {
                matrix[i][0] = 0;
            }
        }
    }
};
        /*
            Idea is to use first row and first col to store flag of elements
        */