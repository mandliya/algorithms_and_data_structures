// https: // practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &m, vector<vector<int>> &vis, vector<string> &ds, string move, int n)
    {
        if (i == n - 1 and j == n - 1)
        {
            ds.push_back(move);
            return;
        }

        // Down
        if (i + 1 < n and !vis[i + 1][j] and m[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, m, vis, ds, move + 'D', n);
            vis[i][j] = 0;
        }

        // Left
        if (j - 1 >= 0 and !vis[i][j - 1] and m[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, m, vis, ds, move + 'L', n);
            vis[i][j] = 0;
        }

        // Right
        if (j + 1 < n and !vis[i][j + 1] and m[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, m, vis, ds, move + 'R', n);
            vis[i][j] = 0;
        }

        // Up
        if (i - 1 >= 0 and !vis[i - 1][j] and m[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, m, vis, ds, move + 'U', n);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {

        string move;
        vector<string> ds;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (m[0][0] == 1)
        {
            solve(0, 0, m, vis, ds, move, n);
        }

        return ds;
    }
};
