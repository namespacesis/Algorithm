#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;
using ll = long long;

const int MAX_N = 100001;
const int MAX_K = 18;

int N, Q;
vector<pair<int, int>> graph[MAX_N];
int parent[MAX_N][MAX_K];
int depth[MAX_N];
ll dist_from_root[MAX_N];

void dfs(int current, int p_node, int d, ll dist) {
    depth[current] = d;
    parent[current][0] = p_node;
    dist_from_root[current] = dist;

    for (auto& edge : graph[current]) {
        int next_node = edge.first;
        int edge_cost = edge.second;
        if (next_node != p_node) {
            dfs(next_node, current, d + 1, dist + edge_cost);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = MAX_K - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent[u][k];
        }
    }

    if (u == v) return u;

    for (int k = MAX_K - 1; k >= 0; --k) {
        if (parent[u][k] != 0 && parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    
    return parent[u][0];
}

int main() {
    FastIO;

    cin >> N >> Q;
    int a, b, c;
    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1, 0, 1, 0);

    for (int k = 1; k < MAX_K; ++k) {
        for (int i = 1; i <= N; ++i) {
            if (parent[i][k - 1] != 0) {
                parent[i][k] = parent[parent[i][k - 1]][k - 1];
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        int l = lca(a, b);
        ll res = dist_from_root[a] + dist_from_root[b] - 2 * dist_from_root[l];
        cout << res << endl;
    }

    return 0;
}