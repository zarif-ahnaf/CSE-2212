#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0 ; i < m;i++){
        int u,v,c;
        cin >> u >> v>>c;
        edges.push_back({u,v,c});
    }
    int src;
    cin >> src;
    vector<int> dist(n,INF);
    dist[src] = 0 ;

    for(int iter = 0;iter<n-1;iter++){
        for(auto e :edges){
            int u = e[0];
            int v = e[1];
            int c = e[2];

            dist[v] = min(dist[v],c+dist[u]);        }
    }

    for(auto I:dist){
                cout << I << " ";

    }
}
