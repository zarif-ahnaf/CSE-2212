#include <bits/stdc++.h>
using namespace std;

int main()
{
    int u, v, c, n, e;
    cin >> n >> e;
    int dist[1000] = {(int)INFINITY};
    for (int j = 1; j <= n; j++)
    {
        dist[j] = (int)INFINITY;
    }
    
    vector<pair<int, int>> adj[100];
    while (e--)
    {
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    priority_queue<pair<int, int>> pq;
    int s;
    cin >> s;
    dist[s] = 0;
    int d;
    cin >> d;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int e = p.second;
        int ec = -(p.first);

        if (dist[e] < ec)
            continue;
        for (int i = 0; i < adj[e].size(); i++)
        {
            int cst = adj[e][i].second;
            int v = adj[e][i].first;
            if (dist[v] > cst + ec)
            {
                dist[v] = dist[e] + cst;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    cout << dist[d] << endl;
}