class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(),i;
        int count = 0;
        int d;
        for(i=2;i<n;i++) {
            d = A[i] - A[i-1];
            int j = i-1;
            while(j > 0 && A[j] - A[j-1] == d) {
                count++;
                j--;
            }
        }
        return count;
    }
};