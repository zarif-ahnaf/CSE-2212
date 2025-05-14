#include<bits/stdc++.h>
using namespace std;
int dist[100][100];

const int INF = 10000000;

int main(){
    for(int i =0;i<100;i++){
        for(int j =0;j<100;j++){
            if(i!=j){
                dist[i][j] = INF;
            }else{
                dist[i][j]  = 0;
                }
        }
    }
    int n,e;
    cout << "Enter the total number of nodes: ";
    cin >> n;
    cout << "Enter the total amount of edges: ";
    cin >> e;
    cout << "Enter edges with cost";
    while(e--){
        int u,v,c;
        cin >> u >> v >> c;
        dist[u][v] = c;
    }

    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i =1;i<=n;i++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][k] = dist[i][k]+dist[k][j];
                    cout << "Distance " << i << " to " << j << " is " << dist[i][j] << endl;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter Source and destination:" << endl;
    int src, dest;
    cin >> src >> dest;
    cout << "Distance from " << src << " to " << dest << " is: " << dist[src][dest] << endl;
}
