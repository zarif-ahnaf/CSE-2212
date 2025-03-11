#include <bits/stdc++.h>
using namespace std;

/*
6 8
0 1 4
0 4 4
1 4 2
4 3 3
3 2 2
4 2 6
4 5 1
5 2 3
1 5
*/

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
    for (int i = 0; i < e; i++)
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
        // pair<int int> p = pq.top();
        auto p = pq.top();
        pq.pop();
        int e = p.second;
        int ec = -(p.first);
        if (dist[e] < ec)
        {
            continue;
        }
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