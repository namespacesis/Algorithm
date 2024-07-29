#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int F1, F2;
int MAX_W = 0;

bool bfs(int W) {
    queue<int> q;
    q.push(F1);
    visited[F1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == F2) {
            return true;
        }

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextW = graph[cur][i].second;

            if (nextW >= W && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int S, E, W;
        cin >> S >> E >> W;

        graph[S].push_back({ E, W });
        graph[E].push_back({ S, W });

        MAX_W = max(MAX_W, W);
    }

    cin >> F1 >> F2;

    int left = 1;
    int right = MAX_W;
    int result = 0;

    while (left <= right) {
        memset(visited, false, N + 1);

		int mid = (left + right) / 2;

		if (bfs(mid)) {
			result = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
    
    cout << result << "\n";

    return 0;
}
