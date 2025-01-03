class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& path, vector<int> adj[]) {
        vis[node] = 1;
        path[node] = 1;

        bool res = true;
        for(int i: adj[node]) {
            if(!vis[i]) {
                res = res & dfs(i, vis, path, adj);
            }
            else if(path[i]) {
                return false;
            }
        }
        path[node] = 0;
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);

        bool res = true;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                res = res & dfs(i, vis, path, adj);
            }
        }
        return res;
    }
};