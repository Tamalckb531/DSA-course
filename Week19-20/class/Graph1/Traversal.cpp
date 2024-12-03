#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    //? first int -> u
    //? second int -> v
    //? third int -> weight
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        //? direction == 0 => undirected graph
        //? direction == 1 => directed graph

        if (direction == 0)
        {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        else
        {
            adjList[u].push_back({v, weight});
        }
    }
    void printAdjList(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            cout << "{ ";
            list<pair<int, int>> temp = adjList[i];
            for (auto j : temp)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << " }" << endl;
        }
    }
    void bfsTraversal(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            cout << frontNode << ", ";
            q.pop();

            for (auto neighbour : adjList[frontNode])
            {
                int node = neighbour.first;
                if (!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int src, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        cout << src << ", ";

        for (auto nbr : adjList[src])
        {
            int node = nbr.first;
            if (!visited[node])
            {
                dfsHelper(node, visited);
            }
        }
    }

    void dfsTraversal(int n)
    {
        unordered_map<int, bool> visited;
        //? we may have some disconnected component so we need to call for each src which are not visited
        for (int src = 0; src < n && !visited[src]; src++)
        {
            dfsHelper(src, visited);
        }

        cout << endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Graph g;
    g.addEdge(0, 3, 3, 1);
    g.addEdge(0, 5, 4, 1);
    g.addEdge(0, 2, 1, 1);
    g.addEdge(3, 5, 9, 1);
    g.addEdge(2, 5, 10, 1);
    g.addEdge(5, 4, 6, 1);
    g.addEdge(5, 6, 2, 1);
    g.addEdge(4, 1, 20, 1);
    g.addEdge(6, 1, 8, 1);
    // g.printAdjList(4);
    g.bfsTraversal(0);
    g.dfsTraversal(7);
    return 0;
}