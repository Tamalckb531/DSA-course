#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfsHelper(int node, unordered_map<int, bool> &visited, vector<vector<int>> &adj, unordered_map<int, bool> &dfsTracker)
    {
        visited[node] = true;
        dfsTracker[node] = true;

        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                bool ans = dfsHelper(nbr, visited, adj, dfsTracker);
                if (ans)
                    return true;
            }
            else if (visited[nbr] && dfsTracker[nbr])
                return true;
        }

        dfsTracker[node] = false; //? unmarking the node from the path
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        int ans = false;
        int n = V;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = dfsHelper(i, visited, adj, dfsTracker);
                if (ans)
                    break;
            }
        }

        return ans;
    }
};