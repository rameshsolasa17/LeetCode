class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int zerocol = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    if(j == 0) zerocol = 1;
                    else {
                        mat[i][0] = 0;
                        mat[0][j] = 0;
                    }
                } 
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(j == 0) {
                    if(zerocol) mat[i][j] = 0;
                }
                else if(!mat[0][j] || !mat[i][0]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};