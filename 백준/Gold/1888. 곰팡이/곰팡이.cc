#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int x, y;
    int n;
};

int N, M;
int arr[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny] || arr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
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

    int res = 0;

    while (true) {
        int temp = 0;

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && arr[i][j] > 0) {
                    temp++;
                    visited[i][j] = true;
                    bfs(i, j);
                }
            }
        }

        if (temp == 1) break;

        res++;

        queue<Node> q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] > 0) {
                    q.push({ i, j, arr[i][j] });
                }
            }
        }

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();

            for (int i = -cur.n; i <= cur.n; i++) {
                for (int j = -cur.n; j <= cur.n; j++) {
                    int nx = cur.x + i;
                    int ny = cur.y + j;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                    if (arr[nx][ny] == cur.n) continue;

                    if (arr[nx][ny] == 0) arr[nx][ny] = cur.n;

                    if (arr[nx][ny] < cur.n) arr[nx][ny] = cur.n;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}