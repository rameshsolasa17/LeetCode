class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& q1) {
        int m = g.size(), n = g[0].size();

        vector<int> qz(q1);
        sort(qz.begin(), qz.end());
        unordered_map<int, int> mp;

        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        q.push({g[0][0], 0, 0});
        vis[0][0] = 1;
        int cnt = 0;

        for(int it: qz) {
            while(!q.empty() && q.top()[0] < it) {
                auto p = q.top();
                q.pop();
                cnt++;
                int x = p[1], y = p[2];

                if(x-1 >=0 && !vis[x-1][y]) {
                    vis[x-1][y] = 1;
                    q.push({g[x-1][y], x-1, y});
                }
                if(x+1 < m && !vis[x+1][y]) {
                    vis[x+1][y] = 1;
                    q.push({g[x+1][y], x+1, y});
                }

                if(y+1 < n  && !vis[x][y+1]) {
                    vis[x][y+1] = 1;
                    q.push({g[x][y+1], x, y+1});
                }
                if(y-1 >=0  && !vis[x][y-1]) {
                    vis[x][y-1] = 1;
                    q.push({g[x][y-1], x, y-1});
                }
            }
            mp[it] = cnt;
        }
        vector<int> res;
        for(auto it: q1) {
            res.push_back(mp[it]);
        }
        return res;
    }
};