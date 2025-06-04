class Solution {
public:
    void fun(string s, int n, int op, int cl, vector<string>& res) {
        if(op == cl && op == n) {
            res.push_back(s);
            return ;
        }
        if(op < n) fun(s+"(", n, op+1, cl, res);
        if(op>cl) fun(s+")", n, op, cl+1, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        fun("", n, 0, 0, res);
        return res;
    }
};