class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length() , i;
        vector<bool> toberemoved(n , false);
        stack<int> st;
        for(i=0; i<n; i++) {
            if(s[i]!='(' && s[i]!=')') continue;
            if(s[i]==')') {
                if(st.empty()) toberemoved[i] = 1;
                else st.pop();
            }
            else st.push(i);
        }
        while(!st.empty()) {
            toberemoved[st.top()] = 1;
            st.pop();
        }
        string ans;
        for(i=0; i<n ;i++) {
            if(toberemoved[i]==0) ans.push_back(s[i]);
        }
        return ans;
    }
};