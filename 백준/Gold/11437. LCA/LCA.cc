#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

const int MAXN = 50001;
int N, M;
vector<int> adj[MAXN];
int parent[MAXN];
int depth[MAXN];
bool check[MAXN];

void dfs(int x, int d) {
    check[x] = true;
    depth[x] = d;

    for (int y : adj[x]) {
        if (check[y]) continue;
        parent[y] = x;
        dfs(y, d + 1);
    }
}

int lca(int u, int v) {
    while (depth[u] != depth[v]) {
        if (depth[u] > depth[v]) u = parent[u];
        else v = parent[v];
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        int res = lca(u, v);
        cout << res << "\n";
    }

    return 0;
}
