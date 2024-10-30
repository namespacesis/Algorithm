#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N;
vector<int> arr[3000];
bool visited[3000];
int parent[3000];
bool cycle[3000];
int dist[3000];

bool dfs(int node) {
    visited[node] = true;
    for (auto next : arr[node]) {
        if (!visited[next]) {
            parent[next] = node;
            if (dfs(next)) return true;
        }
        else if (next != parent[node]) {
            int cur = node;
            while (cur != next) {
                cycle[cur] = true;
                cur = parent[cur];
            }
            cycle[next] = true;
            return true;
        }
    }
    visited[node] = false;
    return false;
}

void find_cycle_distances() {
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (cycle[i]) {
            q.push(i);
            dist[i] = 0;
        }
        else {
            dist[i] = -1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : arr[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[x - 1].push_back(y - 1);
        arr[y - 1].push_back(x - 1);
        parent[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        if (dfs(i)) break;
    }

    find_cycle_distances();

    for (int i = 0; i < N; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
