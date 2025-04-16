#include <bits/stdc++.h>
using namespace std;

static const int INF = 99999;
int dis[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dis[a][b] << "\n";
    }

    return 0;
}
