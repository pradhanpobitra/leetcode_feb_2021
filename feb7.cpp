class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, INT_MAX);
        int dis = INT_MAX;
        for(int i=0; s[i]!='\0' ;i++) {
            if(s[i]==c) {
                dis = i;
            }
            if(dis!=INT_MAX) ans[i] = i - dis;
        }
        dis = INT_MAX;
        for(int i=n-1; i>=0 ;i--) {
            if(s[i]==c) dis = i;
            if(dis!=INT_MAX) ans[i] = min(ans[i], dis-i);
        }
        return ans;
    }
};