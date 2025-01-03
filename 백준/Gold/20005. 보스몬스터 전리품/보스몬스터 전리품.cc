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

int M, N, P;
int HP;
char arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dps[26];
int sr, sc;
queue<pair<int, char>> player;

void bfs() {
    queue<Node> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if ('a' <= arr[cur.x][cur.y] && arr[cur.x][cur.y] <= 'z') {
            player.push({ cur.cnt, arr[cur.x][cur.y] });
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == 'X') continue;

            visited[nx][ny] = true;
            q.push({ nx, ny, cur.cnt + 1 });
        }
    }
}

int main() {
    FastIO;

    cin >> M >> N >> P;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'B') {
                sr = i;
                sc = j;
            }
        }
    }

    for (int i = 0; i < P; i++) {
        char c;
        int d;
        cin >> c >> d;
        dps[c - 'a'] = d;
    }

    cin >> HP;

    bfs();

    int res = 0;

    int dmg = 0;
    int time = 0;

    while (HP > 0) {
        time++;
        while (!player.empty()) {
            int cnt = player.front().first;
            char c = player.front().second;
            int d = dps[c - 'a'];
            if (cnt > time) {
                break;
            }
            player.pop();
            dmg += d;
            res++;
        }
        HP -= dmg;
    }

    cout << res << endl;

    return 0;
}
