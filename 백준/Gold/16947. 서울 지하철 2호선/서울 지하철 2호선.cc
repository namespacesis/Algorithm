#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N;
vector<int> arr[3000];
bool visited[3000];
int parent[3000];
bool cycle[3000];

int bfs(int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    visited[node] = true;

    while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

        if (cycle[cur]) return dist;

		for (auto next : arr[cur]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push({next, dist + 1});
		}
	}
}

bool dfs(int node) {
    visited[node] = true;
    for (auto next : arr[node]) {
        if (!visited[next]) {
            parent[next] = node;
            if (dfs(next)) {
				return true;
			}
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

    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        int ret = bfs(i);
        cout << ret << " ";
    }

    return 0;
}
