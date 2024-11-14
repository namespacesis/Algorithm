#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
};

int N, M;
int arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<Node> zList;
vector<int> v;
int res = 0;

int bfs(int x, int y, int idx) {
    queue<Node> q;
    q.push({x, y});
    visited[x][y] = true;
    int ret = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        arr[cur.x][cur.y] = idx;
        ret++;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny] || arr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    res = max(res, ret);
    return ret;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                zList.push_back({ i, j });
            }
        }
    }

    int idx = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                v.push_back(bfs(i, j, idx));
                idx++;
            }
        }
    }

    for (int i = 0; i < zList.size(); i++) {
        set<int> s;

        int x = zList[i].x;
        int y = zList[i].y;
        int cnt = 0;

        for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (arr[nx][ny] == 0) continue;

            if (s.find(arr[nx][ny]) != s.end()) continue;

            s.insert(arr[nx][ny]);
            cnt += v[arr[nx][ny] - 1];
		}

        res = max(res, cnt + 1);
    }

    cout << res << "\n";

    return 0;
}
