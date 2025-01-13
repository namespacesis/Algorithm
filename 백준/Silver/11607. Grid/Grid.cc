#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int cnt;
};

int N, M;
int arr[500][500];
bool visited[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs() {
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == M - 1) {
			return cur.cnt;
		}

        int c = arr[cur.x][cur.y];

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i] * c;
            int ny = cur.y + dy[i] * c;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt + 1});
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
			arr[i][j] = s[j] - '0';
        }
    }

    int res = bfs();

    if (res == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << res << endl;
	}

    return 0;
}