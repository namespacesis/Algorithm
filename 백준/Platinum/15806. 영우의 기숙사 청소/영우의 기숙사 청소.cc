#include <iostream>
#include <queue>

using namespace std;

int N, M, K, T;
queue<pair<int, int>> q;
bool odd[301][301];
bool even[301][301];

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void oddbfs() {
    int s = q.size();
    while (s--) {
        auto p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (odd[nx][ny]) continue;
            odd[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

void evenbfs() {
    int s = q.size();
    while (s--) {
        auto p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (even[nx][ny]) continue;
            even[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K >> T;

    while (M--) {
        int r, c;
        cin >> r >> c;
        q.push({ r, c });
    }

    for (int t = 1; t <= T; t++) {
        if (t % 2 == 1) {
            oddbfs();
        }
        else {
            evenbfs();
        }
    }

    bool result = false;
    while (K--) {
        int r, c;
        cin >> r >> c;
        if (T % 2 == 1) {
            if (odd[r][c]) result = true;
        }
        else {
            if (even[r][c]) result = true;
        }
    }

    cout << (result ? "YES" : "NO") << "\n";

    return 0;
}
