class Solution {
public:
    void solve(int index,string &s,string &t,vector<string> &ans){
        if(s[index]=='\0') {
            ans.push_back(t);
            return;
        }
        
        if( (s[index] >= 'a' && s[index] <= 'z') || (s[index] >= 'A' && s[index] <= 'Z') ) {
            if(s[index] < 97) {
                t.push_back(s[index]);
                solve(index+1,s,t,ans);
                t.pop_back();
                t.push_back(s[index] + 32);
                solve(index+1,s,t,ans);
                t.pop_back();
            }  
            else {
                t.push_back(s[index]);
                solve(index+1,s,t,ans);
                t.pop_back();
                t.push_back(s[index] - 32);
                solve(index+1,s,t,ans);
                t.pop_back();
            }
        }
        else {
            t.push_back(s[index]);
            solve(index+1,s,t,ans);
            t.pop_back();
        }
    } 
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string t;
        solve(0,S,t,ans);
        return ans;
    }
};