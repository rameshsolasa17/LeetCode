class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        for(auto it: grid) {
            for(auto t: it) {
                temp.push_back(t);
            }
        }
        sort(temp.begin(), temp.end());
        int t = temp[0]%x;
        for(int t1: temp) {
            if(t1%x != t) return -1;
        }

        int n = temp.size();

        int res = 0;

        int mid = temp[n/2];
        for(int i: temp) {
            res+=(abs(i - mid)/x);
        }
        return res;
    }
};