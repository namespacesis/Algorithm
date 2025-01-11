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
int arr[501][501];
bool visited[501][501];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int sr, sc;
int res[1001];

void bfs() {
    queue<Node> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = true;

    int cnt = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (arr[cur.x][cur.y] != 0) {
			res[arr[cur.x][cur.y]] = cur.cnt;
			cnt++;
		}

        if (cnt == M) return;

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny, cur.cnt + 1 });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    cin >> sr >> sc;

    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = i + 1;
    }

    bfs();

    for (int i = 1; i <= M; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}