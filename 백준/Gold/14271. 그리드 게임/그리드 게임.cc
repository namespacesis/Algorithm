#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

struct Cell {
    int x;
    int y;
    int cnt;
};

int N, M, K;
char arr[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
unordered_map<int, bool> visited;
queue<Cell> q;
int res = 0;

int getHash(int x, int y) {
    return x * 100000 + y;
}

void bfs() {
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        if (cur.cnt == K) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            int nHash = getHash(nx, ny);

            if (visited[nHash]) continue;

            visited[nHash] = true;
            q.push({nx, ny, cur.cnt + 1});
            res++;
        }
    }
}

int main() {
    FastIO;

	cin >> N >> M;

    char c;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;

            if (c == 'o') {
                visited[getHash(i, j)] = true;
                q.push({i, j, 0});
                res++;
            }
        }
    }

    cin >> K;

    bfs();

    cout << res << endl;

    return 0;
}
