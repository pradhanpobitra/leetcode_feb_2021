class Solution {
public:
    bool isAnagram(string s, string t) {
        int f[26] = {0};
        for(char c : s) f[c-'a']++;
        for(char c : t) f[c-'a']--;
        bool ans = true;
        for(int i=0;i<26;i++) if(f[i]) ans = false;
        return ans;
    }
};