#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, u, v;
    cin >> node >> edge;
    vector<int> adj[1000];
    int visited[100], parent[100], cost[100] = {0};
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d;
    cout << "Enter Search Node:";
    cin >> s;
    cout << "Enter Destination Node:";
    cin >> d;

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = 0;
    cost[s] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int i = 0; i < adj[f].size(); i++)
        {
            int v1 = adj[f][i];
            if (visited[v1] == 0)
            {
                visited[v1] = 1;
                parent[v1] = f;
                cost[v1] = cost[f] + 1;
                q.push(v1);
            }
        }
    }

    cout << endl;
    cout << cost[d] << endl;
    cout << parent[d] << endl;
}