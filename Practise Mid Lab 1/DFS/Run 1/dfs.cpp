#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nodeNeighbour[1000];
    bool isVisited[1000];
    int nodes, edges, u, v;
    cin >> nodes;
    cin >> edges;
    for (int i = 0; i < nodes; i++)
    {
        isVisited[i + 1] = false;
    }

    while (edges--)
    {
        cin >> u >> v;
        nodeNeighbour[u].push_back(v);
        nodeNeighbour[v].push_back(u);
    }

    int startNode;
    cin >> startNode;

    stack<int> s;
    s.push(startNode);

    while (!s.empty())
    {
        int f = s.top();
        s.pop();
        if (!isVisited[f])
        {
            isVisited[f] = true;
        }

        for (int n : nodeNeighbour[f])
        {
            if (!isVisited[f])
            {
                s.push(f);
            }
        }
    }
    return 0;
}