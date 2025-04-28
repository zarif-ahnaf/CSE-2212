#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

int par[MAXN];

int findrep(int r) {
    if (par[r] == r) return r;
    return par[r] = findrep(par[r]);
}

void Union(int a, int b) {
    int u = findrep(a);
    int v = findrep(b);
    if (u != v) par[u] = v;
}

double distance(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double primMST(const vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return 0.0;

    vector<double> key(n, 1e18);
    vector<bool> inMST(n, false);
    key[0] = 0.0;
    double sum = 0.0;

    for (int cnt = 0; cnt < n; cnt++) {
        int u = -1;
        double min_key = 1e18;
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && key[i] < min_key) {
                min_key = key[i];
                u = i;
            }
        }
        if (u == -1) break;
        inMST[u] = true;
        sum += min_key;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] && v != u) {
                double d = distance(points[u], points[v]);
                if (d < key[v]) {
                    key[v] = d;
                }
            }
        }
    }

    return sum;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, r;
        cin >> n >> r;
        vector<Point> cities(n);
        for (int i = 0; i < n; i++) {
            cin >> cities[i].x >> cities[i].y;
        }

        for (int i = 1; i <= n; i++) par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = distance(cities[i], cities[j]);
                if (d <= r) {
                    Union(i + 1, j + 1);
                }
            }
        }

        map<int, vector<Point>> states;
        for (int i = 0; i < n; i++) {
            int root = findrep(i + 1);
            states[root].push_back(cities[i]);
        }

        int K = states.size();

        double road_cost = 0.0;
        for (auto& entry : states) {
            road_cost += primMST(entry.second);
        }

        map<pair<int, int>, double> state_edges;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int s_i = findrep(i + 1);
                int s_j = findrep(j + 1);
                if (s_i != s_j) {
                    double d = distance(cities[i], cities[j]);
                    int s1 = min(s_i, s_j);
                    int s2 = max(s_i, s_j);
                    pair<int, int> key = {s1, s2};
                    if (state_edges.find(key) == state_edges.end() || d < state_edges[key]) {
                        state_edges[key] = d;
                    }
                }
            }
        }

        vector<pair<double, pair<int, int>>> edges;
        for (auto& entry : state_edges) {
            edges.push_back({entry.second, entry.first});
        }
        sort(edges.begin(), edges.end());

        double rail_cost = 0.0;
        if (K > 1) {
            map<int, int> par_state;
            for (auto& entry : states) {
                par_state[entry.first] = entry.first;
            }

            int count = 0;
            for (auto& edge : edges) {
                double d = edge.first;
                int s1 = edge.second.first;
                int s2 = edge.second.second;

                int u = s1;
                while (par_state[u] != u) u = par_state[u] = par_state[par_state[u]];
                int v = s2;
                while (par_state[v] != v) v = par_state[v] = par_state[par_state[v]];

                if (u != v) {
                    par_state[u] = v;
                    rail_cost += d;
                    count++;
                    if (count == K - 1) break;
                }
            }
        }

        int road_rounded = round(road_cost);
        int rail_rounded = round(rail_cost);

        cout << "Case #" << t << ": " << K << " " << road_rounded << " " << rail_rounded << endl;
    }

    return 0;
}
