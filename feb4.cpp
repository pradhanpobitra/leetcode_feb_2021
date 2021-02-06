class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> h;
        h[nums[0]] = 1;
        int mx = 0;
        for (int i = 1; i < (int)nums.size(); i++)
        {
            h[nums[i]]++;
            if (h[nums[i] - 1])
                mx = max(mx, h[nums[i] - 1] + h[nums[i]]);
            if (h[nums[i] + 1])
                mx = max(mx, h[nums[i] + 1] + h[nums[i]]);
        }
        return mx;
    }
};