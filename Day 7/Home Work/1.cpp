#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int _minmax[101][101];

int main()
{
    int C, S, Q;
    int case_num = 0;
    while (cin >> C >> S >> Q, C != 0)
    {
        case_num++;
        if (case_num > 1)
            cout << endl;

        for (int i = 1; i <= C; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                _minmax[i][j] = INF;
            }
            _minmax[i][i] = 0;
        }

        for (int i = 0; i < S; i++)
        {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            _minmax[c1][c2] = min(_minmax[c1][c2], d);
            _minmax[c2][c1] = min(_minmax[c2][c1], d);
        }

        for (int k = 1; k <= C; k++)
        {
            for (int i = 1; i <= C; i++)
            {
                for (int j = 1; j <= C; j++)
                {
                    int temp = max(_minmax[i][k], _minmax[k][j]);
                    if (temp < _minmax[i][j])
                    {
                        _minmax[i][j] = temp;
                    }
                }
            }
        }

        cout << "Case #" << case_num << endl;

        // Process queries
        for (int i = 0; i < Q; i++)
        {
            int u, v;
            cin >> u >> v;
            if (_minmax[u][v] == INF)
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << _minmax[u][v] << endl;
            }
        }
    }
    return 0;
}
