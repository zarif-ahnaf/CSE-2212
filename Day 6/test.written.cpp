#include <bits/stdc++.h>
using namespace std;

int dis[100][100];

/*
4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4
*/
int main()
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i != j)
                dis[i][j] = 1000000;
            else
                dis[i][j] = 0;
        }
    }
    int n, e;
    cin >> n;
    cin >> e;
    while (e--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        dis[u][v] = cost;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int test;
    cin >> test;
    while (test--)
    {
        int src, dest;
        cin >> src >> dest;
        if (dis[src][dest] == 1000000)
        {
            cout << -1 << endl;
        }

        else
        {
            cout << dis[src][dest] << endl;
        }
    }
}
