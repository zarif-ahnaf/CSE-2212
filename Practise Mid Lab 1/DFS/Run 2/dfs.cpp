#include <bits/stdc++.h>
using namespace std;

vector<int> nodeNeighbour[1000];
bool isVisited[1000];

int main()
{
    int nodes, edges, u, v;
    cin >> nodes >> edges;
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

    int start;
    cin >> start;

    stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int popped = s.top();
        s.pop();

        if (!isVisited[popped])
        {
            isVisited[popped] = true;
        }
        for (auto p : nodeNeighbour[popped])
        {
            if (!isVisited[p])
            {
                s.push(p);
            }
        }
    }
}