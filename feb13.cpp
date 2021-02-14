class Solution
{
public:
#define pipii pair<int, pair<int, int>>
#define mp make_pair
    int rows, cols;
    bool isvalid(int x, int y)
    {
        if (x < 0 || y < 0 || x >= rows || y >= cols)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int i, j;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        pq.push(mp(1, mp(0, 0)));
        if (grid[0][0])
            return -1;
        while (!pq.empty())
        {
            pipii p = pq.top();
            pq.pop();
            if (p.second.first == rows - 1 && p.second.second == cols - 1)
                return p.first;
            int x = p.second.first;
            int y = p.second.second;
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            if (isvalid(x, y - 1) && grid[x][y - 1] == 0)
                pq.push(mp(p.first + 1, mp(x, y - 1)));
            if (isvalid(x, y + 1) && grid[x][y + 1] == 0)
                pq.push(mp(p.first + 1, mp(x, y + 1)));
            if (isvalid(x - 1, y) && grid[x - 1][y] == 0)
                pq.push(mp(p.first + 1, mp(x - 1, y)));
            if (isvalid(x + 1, y) && grid[x + 1][y] == 0)
                pq.push(mp(p.first + 1, mp(x + 1, y)));
            if (isvalid(x - 1, y + 1) && grid[x - 1][y + 1] == 0)
                pq.push(mp(p.first + 1, mp(x - 1, y + 1)));
            if (isvalid(x + 1, y + 1) && grid[x + 1][y + 1] == 0)
                pq.push(mp(p.first + 1, mp(x + 1, y + 1)));
            if (isvalid(x + 1, y - 1) && grid[x + 1][y - 1] == 0)
                pq.push(mp(p.first + 1, mp(x + 1, y - 1)));
            if (isvalid(x - 1, y - 1) && grid[x - 1][y - 1] == 0)
                pq.push(mp(p.first + 1, mp(x - 1, y - 1)));
        }
        return -1;
    }
};