class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int k=0;k<n;k++) {
            int i=k, j=0;
            vector<int> v;
            while(i<n && j<n) {
                v.push_back(grid[i][j]);
                i++; j++;
            }
            sort(v.rbegin(), v.rend());
            i = k, j = 0;
            int l = 0;
            while(i<n && j<n) {
                grid[i][j] = v[l++];
                i++; j++;
            }
        }

        for(int k=1;k<n;k++) {
            int i=0, j=k;
            vector<int> v;
            while(i<n && j<n) {
                v.push_back(grid[i][j]);
                i++; j++;
            }
            sort(v.begin(), v.end());
            i = 0, j = k;
            int l = 0;
            while(i<n && j<n) {
                grid[i][j] = v[l++];
                i++; j++;
            }
        }

        return grid;
    }
};