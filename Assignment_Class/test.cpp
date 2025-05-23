#include <bits/stdc++.h>
using namespace std;

int par[10005];

int findrep(int u) {
    if (par[u] == u) {
        return u;
    }
    par[u] = findrep(par[u]);
    return par[u];
}


bool unite(int u, int v)
{
    u = findrep(u);
    v = findrep(v);
    if (u == v) return false;
    par[u] = v;
    return true;
}

int main()
{
    int n, m, T;
    cin >> n >> m >> T;

    // cost, impact, u, v
    vector<tuple<int,int,int,int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c, e;
        cin >> u >> v >> c >> e;
        edges.emplace_back(c, e, u, v);
    }

    sort(edges.begin(), edges.end(),
         [](auto &A, auto &B)
    {
        if (get<1>(A) != get<1>(B))
            return get<1>(A) < get<1>(B);
        return get<0>(A) < get<0>(B);
    });

    for (int i = 1; i <= n; ++i)
        par[i] = i;

    long long total_cost = 0;
    long long sum_e = 0;
    int edges_used = 0;

    for (auto &ed : edges)
    {
        int c= get<0>(ed);
        int e_val = get<1>(ed);
        int u = get<2>(ed);
        int v= get<3>(ed);

        if (unite(u, v))
        {
            total_cost += c;
            sum_e+= e_val;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }

    if (edges_used == n - 1 && sum_e < T)
    {
        cout << total_cost;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    cout << endl;

    return 0;
}
