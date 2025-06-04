class Solution {
public:
    bool isDigit(char c) {
        return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
    }
    void fun(string s, int i, long int& res, int& flag) {
        if(flag && !isDigit(s[i])) {
            return ;
        }


        if(s[i] == ' ') {
            fun(s, i+1, res, flag);
            return ;
        }
        if(s[i] == '-') {
            flag = -1;
            fun(s, i+1, res, flag);
            return ;
        }
        if(s[i] == '+') {
            flag = 1;
            fun(s, i+1, res, flag);
            return ;
        }

        if(isDigit(s[i])) {
            if(flag == 0) flag = 1;

            if(flag == -1) {
                if(res*10 > -2147483648) {
                    res = res * 10;
                }
                else res = -2147483648;

                if(res - (s[i] - '0') > -2147483648) {
                    res = res - (s[i] - '0');
                }
                else res = -2147483648;
            }
            
            if(flag == 1) {
                if(res*10 < 2147483647) {
                    res = res * 10;
                }
                else res = 2147483647;

                if(res + s[i] - '0' < 2147483647) {
                    res = res + s[i] - '0';
                }
                else res = 2147483647;
            }
            fun(s, i+1, res, flag);
            return ;
        }

    }
    int myAtoi(string s) {
        long int res = 0;
        int flag = 0;
        fun(s, 0, res, flag);
        return res;
    }
};