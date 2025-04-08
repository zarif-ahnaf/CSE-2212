#include <bits/stdc++.h>
using namespace std;

int main()
{
    int u, v, c, n, e;
    int dist[10000] = {(int)INFINITY};
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = (int)INFINITY;
    }

    vector<pair<int, int>> adj[1000];
    while (e--)
    {
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    int s, d;
    cin >> s >> d;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int e = p.second;
        int ec = -(p.first);
        for (int i = 0; i < adj[e].size(); i++)
        {
            int v = adj[e][i].first;
            int cst = adj[e][i].second;

            if (dist[v] > dist[e] + cst)
            {
                dist[v] = dist[e] + cst;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
    cout << dist[d] << endl;
}