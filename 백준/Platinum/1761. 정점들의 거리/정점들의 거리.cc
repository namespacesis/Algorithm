#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

const int MAXN = 40001;
const int LOG = 17;
int N, M;
vector<pair<int, int>> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int dist[MAXN];
bool check[MAXN];

void dfs(int x, int d, int l) {
    check[x] = true;
    depth[x] = d;
    dist[x] = l;

    for (pair<int, int> y : adj[x]) {
        if (check[y.first]) continue;
        parent[y.first][0] = x;
        dfs(y.first, d + 1, l + y.second);
    }
}

void build() {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= N; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[v] - depth[u] >= (1 << i)) {
            v = parent[v][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int findDist(int u, int v) {
    int ca = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[ca];
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({ v, d });
        adj[v].push_back({ u, d });
    }

    dfs(1, 0, 0);
    build();

    cin >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        cout << findDist(u, v) << "\n";
    }

    return 0;
}
