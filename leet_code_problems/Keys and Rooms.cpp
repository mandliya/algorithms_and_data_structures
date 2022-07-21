// https : // leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int V = rooms.size();
        vector<int> vis(V, 0);

        if (!vis[0])
        {
            queue<int> q;
            q.push(0);
            vis[0] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : rooms[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }

        for (auto it : vis)
            if (it == 0)
                return false;

        return true;
    }
};