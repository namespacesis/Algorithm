#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

const int MAXN = 100001;
const int LOG = 17;
int N, M;
vector<int> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
bool check[MAXN];

void dfs(int x, int d) {
    check[x] = true;
    depth[x] = d;

    for (int y : adj[x]) {
        if (check[y]) continue;
        parent[y][0] = x;
        dfs(y, d + 1);
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
    build();

    cin >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        int res = lca(u, v);
        cout << res << "\n";
    }

    return 0;
}
