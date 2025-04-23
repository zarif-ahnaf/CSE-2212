#include <bits/stdc++.h>
using namespace std;

int dis[100][100];

/*
4 6
1 2 1
2 1 4
2 3 3
1 3 -2
3 4 2
4 1 5
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
    cout << "Enter the total node: " << endl;
    cin >> n;
    cout << "Enter the total edge: " << endl;
    cin >> e;
    cout << "Enter the edges wiht cost: " << endl;
    while (e--)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        dis[u][v] = cost;
        // dis[v][u] = cost;
    }
    cout << "Algorithm Begin here" << endl;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    cout << "Distance " << i << " to " << j << " is " << dis[i][j] << endl;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter Source and destination:" << endl;
    int src, dest;
    cin >> src >> dest;
    cout << "Distance from " << src << " to " << dest << " is: " << dis[src][dest] << endl;
}
