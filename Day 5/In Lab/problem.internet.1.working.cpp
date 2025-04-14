#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

// Runs Bellman–Ford from a super‑source 0 (connected to every 1..n with weight 0).
// edges: list of (u→v, weight w)
// Outputs:
//   dist[0..n]: dist[v] = min cost from any start u to v
//   neg[0..n]: neg[v] = true if v is reachable from some negative cycle
void bellmanFordSuper(int n,
                      const vector<tuple<int, int, ll>> &edges,
                      vector<ll> &dist,
                      vector<char> &neg)
{
    dist.assign(n + 1, INF);
    neg.assign(n + 1, 0);
    dist[0] = 0;

    // Relax edges (including super‑source) n times
    for (int it = 1; it <= n; it++)
    {
        bool any = false;

        // relax original edges
        for (auto &e : edges)
        {
            int u, v;
            ll w;
            tie(u, v, w) = e;
            if (dist[u] < INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                any = true;
                if (it == n)
                    neg[v] = 1;
            }
        }

        // relax super‑source 0 -> v at cost 0
        for (int v = 1; v <= n; v++)
        {
            if (dist[v] > dist[0])
            {
                dist[v] = dist[0];
                any = true;
                if (it == n)
                    neg[v] = 1;
            }
        }

        if (!any)
            break;
    }

    // propagate negative‑cycle flags along the graph
    vector<vector<int>> adj(n + 1);
    for (auto &e : edges)
    {
        int u, v;
        ll w;
        tie(u, v, w) = e;
        adj[u].push_back(v);
    }
    queue<int> q;
    vector<char> seen(n + 1, 0);
    for (int v = 1; v <= n; v++)
    {
        if (neg[v])
        {
            q.push(v);
            seen[v] = 1;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int w : adj[u])
        {
            if (!seen[w])
            {
                seen[w] = 1;
                neg[w] = 1;
                q.push(w);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<tuple<int, int, ll>> edges, redges;
        edges.reserve(m);
        redges.reserve(m);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
            redges.emplace_back(v, u, w); // reversed edge
        }

        vector<ll> dist_to, dist_from;
        vector<char> neg_to, neg_from;

        // shortest-to-v
        bellmanFordSuper(n, edges, dist_to, neg_to);
        // shortest-from-v (i.e. to-v in reversed graph)
        bellmanFordSuper(n, redges, dist_from, neg_from);

        // combine and print
        for (int v = 1; v <= n; v++)
        {
            if (neg_to[v] || neg_from[v])
            {
                cout << "INF\n";
            }
            else
            {
                cout << (dist_to[v] + dist_from[v]) << "\n";
            }
        }
    }
    return 0;
}
