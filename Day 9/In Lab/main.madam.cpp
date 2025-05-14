#include <bits/stdc++.h>
using namespace std;
int cost[100];
int weight[100];

int n, w;
int dp[1000][1000];

/*
4 5
3 4
2 3
5 6
4 5
*/
int func(int idx, int wt)
{
    if (wt < 0)
        return -10000000;
    if (idx > n)
        return 0;
    if (dp[idx][wt] != -1)
        return dp[idx][wt];
    int p1 = cost[idx] + func(idx + 1, wt - weight[idx]);
    int p2 = func(idx + 1, wt);
    return dp[idx][wt] = max(p1, p2);
}
int main()
{
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> cost[i];
    }
    cout << func(1, w) << endl;

    return 0;
}
