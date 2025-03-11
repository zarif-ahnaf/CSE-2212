#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int node, edge, u, v;
    cin >> node >> edge;
    vector<int> adj[1000];
    int visited[1000] = {0};
    int parent[1000] = {0};
    int cost[1000] = {0};

    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, d;
    cout << "Enter Start Node: ";
    cin >> s;
    cout << "Enter Destination Node: ";
    cin >> d;

    queue<int> q;
    vector<int> bfsOrder;
    q.push(s);
    visited[s] = 1;
    parent[s] = 0;
    cost[s] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";

        for (int i = 0; i < adj[f].size(); i++)
        {
            int v1 = adj[f][i];
            if (visited[v1] == 0)
            {
                visited[v1] = 1;
                parent[v1] = f;
                cost[v1] = cost[f] + 1;
                q.push(v1);
            }
        }
    }
    cout << endl;

    cout << "Distance from " << s << " to " << d << ": " << cost[d] << endl;
    cout << "Parent of destination " << d << ": " << parent[d] << endl;

    vector<int> path;
    int cur = d;
    while (cur != s)
    {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    cout << "Shortest Path: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
            cout << "->";
    }
    cout << endl;

    return 0;
}
