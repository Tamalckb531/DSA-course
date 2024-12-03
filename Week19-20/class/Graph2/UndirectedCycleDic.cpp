#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        //? direction == 0 => undirected graph
        //? direction == 1 => directed graph

        if (direction == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            adjList[u].push_back(v);
        }
    }
    bool bfsCycleDetection(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        //? initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        //? bfs logic
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }

                //? cycle detection logic
                else if (visited[nbr] && nbr != parent[frontNode])
                    return true;
            }
        }
        return false;
    }

    bool dfsCycleDetection(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool ans = dfsCycleDetection(nbr, visited, src);
                if (ans)
                    return true;
            }
            else if (visited[nbr] && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(2, 3, 0);
    int n = 4;

    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // ans = g.bfsCycleDetection(i, visited);
            ans = g.dfsCycleDetection(i, visited, -1);
            if (ans)
                break;
        }
    }

    if (ans)
        cout << "Cycle present" << endl;
    else
        cout << "Cycle not present" << endl;

    return 0;
}