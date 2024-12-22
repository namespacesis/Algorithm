#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int N, M, K;
ll X;
ll arr[500][500];
bool visited[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int x, int y, ll mid) {
	int ret = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
	visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] >= X - mid) continue;
            visited[nx][ny] = true;
            q.push({ nx, ny });
            ret++;
        }
    }

    return ret;
}

int getCnt(ll mid) {
    int ret = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] >= X - mid) continue;
            if (visited[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (abs(arr[i][j] - arr[nx][ny]) <= mid) continue;
                ret += bfs(i, j, mid);
                break;
            }
        }
    }

    return ret;
}

int main() {
    FastIO;

    cin >> N >> M >> K >> X;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    ll left = 0, right = X;

    while (left <= right) {
        ll mid = (left + right) / 2;

        int cnt = getCnt(mid);

        if (cnt > K) left = mid + 1;
		else right = mid - 1;
    }

    cout << left << endl;

    return 0;
}