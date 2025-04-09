#include <bits/stdc++.h>
using namespace std;

/*
3
3 2
1 2 5
2 3 7
1 3
3 3
1 2 4
1 3 7
2 3 1
1 3
3 1
1 2 4
1 3
*/

int main()
{
    int ask;
    cout << "How many times do you want to take input?" << endl;
    cin >> ask;
    while (ask--)
    {
        int u, v, c, e, n;
        cin >> n >> e;
        int dist[1000] = {(int)INFINITY};
        for (int i = 1; i <= n; i++)
        {
            dist[i] = (int)INFINITY;
        }

        vector<pair<int, int>> adj[100];
        while (e--)
        {
            cin >> u >> v >> c;
            adj[u].push_back(make_pair(v, c));
            adj[v].push_back(make_pair(u, c));
        }

        int s, d;
        priority_queue<pair<int, int>> pq;
        cin >> s;
        cin >> d;
        dist[s] = 0;
        pq.push(make_pair(0, s));
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
        if (dist[d] == (int)INFINITY)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << dist[d] << endl;
    }
}