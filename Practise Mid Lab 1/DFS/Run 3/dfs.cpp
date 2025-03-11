#include <bits/stdc++.h>
using namespace std;

vector<int> nodeNeighbour[10000];
bool isVisited[10000] = {false};

int main()
{
    int u, v, edges, nodes;
    cin >> nodes >> edges;
    while (edges--)
    {
        cin >> u >> v;
        nodeNeighbour[u].push_back(v);
        nodeNeighbour[v].push_back(u);
    }

    int s;
    cin >> s;
    stack<int> stac;

    stac.push(s);
    while (!stac.empty())
    {
        auto p = stac.top();
        stac.pop();
        if (!isVisited[p])
        {
            isVisited[p] = true;
            cout << p << " ";
        }
        for (auto a : nodeNeighbour[p])
        {
            if (!isVisited[a])
            {
                stac.push(a);
            }
        }
    }
}