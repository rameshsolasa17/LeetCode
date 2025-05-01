class Solution {
public:
    bool check(vector<int>& t, multiset<int> &wfree, int &mid, int p, int &s) {
        for(int i = mid - 1; i >= 0; --i) {
            auto it = prev(wfree.end());
            
            if(*it < t[i]) {
                it = wfree.lower_bound(t[i] - s);
                if(it == wfree.end())  return false;
                p--;
                if (p == -1) return false;
            }
            wfree.erase(it);
        }
        return true;
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        int l = 0, h = min(t.size(), w.size());

        sort(t.begin(), t.end());
        sort(w.begin(), w.end());

        while(l < h) {
            int mid = (l+h+1)/2;
            multiset<int> wfree(w.end() - mid, w.end());
            if(check(t, wfree, mid, p, s)) l = mid;
            else h = mid-1;
        }
        return l;
    }
};

/*
KEY LEARNINGS:
1- assign hard workers to less requirement tasks, to make sure the current answer is valid.
2- GOOO for binary search to find maximum or minimum.
*/