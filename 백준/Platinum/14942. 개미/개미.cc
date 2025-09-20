#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

const int MAX_N = 100001;
const int MAX_K = 18;
int N;
int E[MAX_N];
vector<pair<int, int>> graph[MAX_N];
bool visited[MAX_N];
int parent[MAX_N][MAX_K];
int cost[MAX_N][MAX_K];

void dfs(int idx) {
    for (auto e : graph[idx]) {
        if (visited[e.first]) continue;

        parent[e.first][0] = idx;
        cost[e.first][0] = e.second;

        visited[e.first] = true;
        dfs(e.first);
        visited[e.first] = false;
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> E[i];
    }
    
    int a, b, c;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    visited[1] = true;
    dfs(1);

    for (int k = 1; k < ceil(log2(N)); k++) {
        for (int i = 1; i <= N; i++) {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
            cost[i][k] = cost[i][k - 1] + cost[parent[i][k - 1]][k - 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        int cur = i;
        int energy = E[i];
        for (int k = ceil(log2(N)) - 1; k >= 0; k--) {
            if (parent[cur][k] != 0 && cost[cur][k] <= energy) {
                energy -= cost[cur][k];
                cur = parent[cur][k];
            }
        }

        cout << cur << endl;
    }
}