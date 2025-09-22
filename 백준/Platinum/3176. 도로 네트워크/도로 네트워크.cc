#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

const int MAX_N = 100001;
const int MAX_K = 18;
int N, K;
vector<pair<int, int>> graph[MAX_N];
int depth[MAX_N];
int parent[MAX_N][MAX_K];
int min_path[MAX_N][MAX_K];
int max_path[MAX_N][MAX_K];

void dfs(int idx, int d) {
    depth[idx] = d;
    for (auto e : graph[idx]) {
        if (depth[e.first] != 0) continue;

        parent[e.first][0] = idx;
        min_path[e.first][0] = e.second;
        max_path[e.first][0] = e.second;

        dfs(e.first, d + 1);
    }
}

pair<int, int> query(int u, int v) {
    int min_res = 1e9;
    int max_res = 0;

    if (depth[u] < depth[v]) swap(u, v);

    for (int k = MAX_K - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            min_res = min(min_res, min_path[u][k]);
            max_res = max(max_res, max_path[u][k]);
            u = parent[u][k];
        }
    }

    if (u == v) return {min_res, max_res};

    for (int k = MAX_K - 1; k >= 0; --k) {
        if (parent[u][k] != 0 && parent[u][k] != parent[v][k]) {
            min_res = min({min_res, min_path[u][k], min_path[v][k]});
            max_res = max({max_res, max_path[u][k], max_path[v][k]});
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    min_res = min({min_res, min_path[u][0], min_path[v][0]});
    max_res = max({max_res, max_path[u][0], max_path[v][0]});

    return {min_res, max_res};
}

int main() {
    FastIO;

    cin >> N;

    int a, b, c;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1, 1);

    for (int k = 1; k < MAX_K; k++) {
        for (int i = 1; i <= N; i++) {
            int p = parent[i][k - 1];
            if (p == 0) continue;
            parent[i][k] = parent[p][k - 1];
            min_path[i][k] = min(min_path[i][k-1], min_path[p][k-1]);
            max_path[i][k] = max(max_path[i][k-1], max_path[p][k-1]);
        }
    }

    cin >> K;

    int D, E;

    for (int i = 0; i < K; i++) {
        cin >> D >> E;
        
        pair<int, int> res = query(D, E);

        cout << res.first << " " << res.second << endl;
    }

    return 0;
}