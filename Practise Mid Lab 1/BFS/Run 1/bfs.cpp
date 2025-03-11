#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges, u, v;
    vector<int> adj[1000];
    int visited[100];
    int cost[100];
    int parent[100];

    cin >> nodes >> edges;
    while (edges--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    cost[s] = 0;
    parent[s] = 0;
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