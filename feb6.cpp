class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root,int &mxlevel,int currlevel) {
        if(root==0) return;
        if(currlevel > mxlevel) {
            ans.push_back(root->val);
            mxlevel = currlevel; 
        }
        preorder(root->right,mxlevel,currlevel+1);
        preorder(root->left,mxlevel,currlevel+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        int mxlevel = 0;
        preorder(root,mxlevel,1);
        return ans;
    }
};