class Solution {
public:
    bool dfs(int i, int j,  vector<vector<char>>& b, string w, int temp) {
        if(temp == w.size()) return true;
        int n = b.size();
        int m = b[0].size();
        if(i>=0 && i<n && j>=0 && j<m && b[i][j] != '*' && w[temp] == b[i][j]) {
            char c = b[i][j];
            b[i][j] = '*';
            // cout<<b[i][j];
            bool down = dfs(i+1, j, b, w, temp+1);
            bool top = dfs(i-1, j, b, w, temp+1);
            bool right = dfs(i, j+1, b, w, temp+1);
            bool left = dfs(i, j-1, b, w, temp+1);

            b[i][j] = c;

            return top || down || left || right;
        }
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n = b.size();
        int m = b[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] == w[0]) {
                    if(dfs(i, j, b, w, 0)) return true;
                }
            }
        }
        return false;
    }
};