#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, M, K;
int arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int maxV = 0;
int minV = 1000001;

int bfs(int mid) {
	queue<pair<int, int>> q;
    int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < M; i++) {
		if (arr[0][i] <= mid) {
			q.push({ 0, i });
			visited[0][i] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		if (arr[i][0] <= mid && !visited[i][0]) {
			q.push({ i, 0 });
			visited[i][0] = true;
		}
		if (arr[i][M - 1] <= mid && !visited[i][M - 1]) {
			q.push({ i, M - 1 });
			visited[i][M - 1] = true;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (arr[nx][ny] <= mid && !visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	return cnt;
}

int main() {
    FastIO;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            maxV = max(maxV, arr[i][j]);
            minV = min(minV, arr[i][j]);
        }
    }

    int left = minV;
    int right = maxV;
    int res = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = bfs(mid);

        if (cnt >= K) {
            res = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

	cout << res << "\n";

	return 0;
}
