#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

const int SIZE = 3100;
const int OFFSET = 1550;
bool visited[SIZE][SIZE];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    FastIO;
    int N, M, K;
    cin >> N >> M;

    queue<pair<int, int>> q;
    int res = 0;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            if (row[j] == 'o') {
                int x = i + OFFSET;
                int y = j + OFFSET;
                visited[x][y] = true;
                q.push({x, y});
                res++;
            }
        }
    }

    cin >> K;

    while (K--) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    res++;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}