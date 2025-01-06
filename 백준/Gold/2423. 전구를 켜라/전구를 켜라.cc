#include <iostream>
#include <deque>
#include <climits>

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
int visited[501][501];
int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };
const int INF = INT_MAX;

bool needRotate(int x, int y, int d) {
    if (d == 0) return arr[x - 1][y] == 0;
    else if (d == 1) return arr[x][y] == 1;
    else if (d == 2) return arr[x][y - 1] == 0;
    else return arr[x - 1][y - 1] == 1;
}

void zeroOneBfs() {
    deque<Node> dq;
    dq.push_back({0, 0, 0});
    visited[0][0] = 0;

    while (!dq.empty()) {
        Node cur = dq.front();
        dq.pop_front();

        if (cur.x == N && cur.y == M) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > M) continue;

            int check = needRotate(cur.x, cur.y, i) ? 1 : 0;

            int ncnt = cur.cnt + check;

            if (visited[nx][ny] <= ncnt) continue;

            visited[nx][ny] = ncnt;
            
            if (check) dq.push_back({ nx, ny, ncnt });
            else dq.push_front({ nx, ny, ncnt });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    char c;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '/') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            visited[i][j] = INF;
        }
    }

    zeroOneBfs();

    if (visited[N][M] == INF) cout << "NO SOLUTION" << endl;
	else cout << visited[N][M] << endl;

    return 0;
}
