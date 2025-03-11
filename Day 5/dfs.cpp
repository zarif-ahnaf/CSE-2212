#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> nodeNeighbour[100002];
bool isVisited[100002];

int main()
{
    int nodes;
    cin >> nodes;
    int edges;
    cin >> edges;
    for (int i = 0; i < nodes; i++)
    {
        isVisited[i + 1] = false;
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        nodeNeighbour[u].push_back(v);
        nodeNeighbour[v].push_back(u);
    }

    int startNode;
    cin >> startNode;

    stack<int> s;
    s.push(startNode);

    while (!s.empty())
    {
        int popped = s.top();
        s.pop();
        if (!isVisited[popped])
        {
            isVisited[popped] = true;
            cout << popped << " ";
        }
        for (int n : nodeNeighbour[popped])
        {
            if (!isVisited[n])
            {
                s.push(n);
            }
        }
    }

    return 0;
}
