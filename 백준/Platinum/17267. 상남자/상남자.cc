#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int l, r;
};

int N, M;
int L, R;
int arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sr, sc;

int bfs() {
    queue<Node> q;
    q.push({sr, sc, L, R});
    visited[sr][sc] = true;

    int ret = 1;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = cur.x;
            int ny = cur.y;

            while (nx >= 0 && nx < N) {
                nx += dx[i];
                if (nx < 0 || nx >= N) break;
                if (arr[nx][ny] == 1) break;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({ nx, ny, cur.l, cur.r });
                ret++;
            }
        }

        for (int i = 2; i < 4; i++) {
            int nx = cur.x;
            int ny = cur.y + dy[i];

            if (i == 2 && cur.r == 0) continue;
            if (i == 3 && cur.l == 0) continue;
            if (ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny, cur.l - (i == 3), cur.r - (i == 2) });
            ret++;
        }
    }

    return ret;
}

int main() {
    FastIO;

    cin >> N >> M;

    cin >> L >> R;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
            if (arr[i][j] == 2) {
                sr = i;
                sc = j;
            }
        }
    }

    int res = bfs();

    cout << res << endl;

    return 0;
}