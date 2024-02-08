#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int N, Q, L;
int A[64][64];
bool visited[64][64];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void rotate(int x, int y, int l) {
    vector<vector<int>> temp(l, vector<int>(l));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            temp[j][l - 1 - i] = A[x + i][y + j];
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            A[x + i][y + j] = temp[i][j];
        }
    }
}

void melt() {
    vector<pair<int, int>> meltList;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (A[x][y] == 0) continue;
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && A[nx][ny] > 0)
                    cnt++;
            }
            if (cnt < 3) meltList.push_back({ x, y });
        }
    }
    for (auto& p : meltList) {
        if (A[p.first][p.second] > 0) A[p.first][p.second]--;
    }
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });
    int size = 1;
    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && A[nx][ny] > 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                size++;
            }
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;
    N = pow(2, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    while (Q--) {
        cin >> L;
        L = pow(2, L);
        for (int x = 0; x < N; x += L) {
            for (int y = 0; y < N; y += L) {
                rotate(x, y, L);
            }
        }
        melt();
    }

    int totalIce = 0, largestSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            totalIce += A[i][j];
            if (A[i][j] > 0 && !visited[i][j]) {
                largestSize = max(largestSize, bfs(i, j));
            }
        }
    }

    cout << totalIce << "\n" << largestSize << "\n";
    return 0;
}
