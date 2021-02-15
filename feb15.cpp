bool myway(const pair<int,int> &a,const pair<int,int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
}
class Solution {
public:
    
    int count(vector<int> &v,int l,int h) {
        if(l > h) return 0;
        int mid = (l+h)/2;
        if(v[mid] == 1) return max(mid+1,count(v,mid+1,h));
        return count(v,l,mid-1);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        int i=0;
        vector<pair<int,int>> temp;
        for(vector<int> x : mat) {
            int c = count(x,0,cols-1);
            temp.push_back(make_pair(c,i));
            i++;
        }
        sort(temp.begin(),temp.end(),myway);
        vector<int> ans;
        i=0;
        while(k--) {
            ans.push_back(temp[i].second);
            i++;
        }
        return ans;
    }
};