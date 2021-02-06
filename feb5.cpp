class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st,st2;
        string temp;
        for(int i=0; path[i]!='\0' ;i++) {
            if(path[i]=='/') {
                if(temp.length()) {
                    if(temp == ".") temp.clear();
                    else if(temp== "..") {
                        temp.clear();
                        if(!st.empty())
                            st.pop();
                    }
                    else { st.push(temp); temp.clear(); }
                }
            }
            else temp.push_back(path[i]);
        }
        if(temp == "..") {
            if(st.size()) st.pop();
        }
        else if( temp.size() && temp != ".") st.push(temp);
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        string ans;
        if(st2.size()==0) return "/";
        while(!st2.empty()) {
             ans.push_back('/');
            ans.append(st2.top());
            st2.pop();
        }
        return ans;
    }
};