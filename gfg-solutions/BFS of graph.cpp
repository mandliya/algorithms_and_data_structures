// https : // practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<int> vis(V + 1, 0);

        if (!vis[0])
        {
            queue<int> q;
            q.push(0);
            vis[0] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        return bfs;
    }
};