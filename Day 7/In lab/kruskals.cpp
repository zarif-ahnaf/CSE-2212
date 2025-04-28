#include <bits/stdc++.h>
using namespace std;

/*
4 5
1 2 1
1 3 4
2 3 2
2 4 7
3 4 3
*/

int par[10000];
int findrep(int r)
{
    if (par[r] == r)
        return r;
    return par[r] = findrep(par[r]);
}

void Union(int a, int b)
{
    int u = findrep(a);
    int v = findrep(b);
    if (u == v)
        cout << "They are already in the same set" << endl;
    else
    {
        par[u] = v;
    }
}
vector<pair<int, pair<int, int>>> edge;

int main()
{
    int n, e, u, v, c;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int k = 0; k < e; k++)
    {
        cin >> u >> v >> c;
        // edge.push_back({c, {u, v}});
        edge.push_back(make_pair(c, make_pair(u, v)));
    }
    sort(edge.begin(), edge.end());
    int mst = 0;
    for (int j = 0; j < edge.size(); j++)
    {
        int cst = edge[j].first;

        int p = edge[j].second.first;
        int q = edge[j].second.second;
        if (findrep(p) != findrep(q))
        {
            Union(p, q);

            mst += cst;
            cout << p << "->" << q << " with cost " << cst << endl;
        }
    }
    cout << mst << endl;
}