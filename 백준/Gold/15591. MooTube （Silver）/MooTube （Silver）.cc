#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, Q;
vector<pair<int, int>> arr[5001];
bool visited[5001];

int bfs(int k, int v) {
    queue<pair<int, int>> q;
    q.push({v, 0});
    visited[v] = true;

    int ret = 0;

    while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cost >= k) {
			ret++;
		}

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextCost = arr[cur][i].second;
            if (cost != 0) nextCost = min(cost, nextCost);

			if (!visited[next]) {
				visited[next] = true;
                q.push({ next, nextCost });
			}
		}
	}

    return ret;
}

int main() {
    FastIO;

    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;

        memset(visited, false, sizeof(visited));

        int ret = bfs(k, v);

        cout << ret << "\n";
    }

    return 0;
}