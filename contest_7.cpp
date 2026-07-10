#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;

    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool changed = false;
        for (const auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    bool negativeCycle = false;
    for (const auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative cycle\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            if (dist[i] == INF) {
                cout << "inf";
            } else {
                cout << dist[i];
            }
        }
        cout << '\n';
    }

    return 0;
}
