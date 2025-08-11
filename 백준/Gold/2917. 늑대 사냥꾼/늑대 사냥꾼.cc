#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

struct Node {
    int safety, r, c;

    bool operator<(const Node& other) const {
        return safety < other.safety;
    }
};

int N, M;
string grid[501];
int safety[501][501];
int max_min_safety[501][501];
int startR, startC, endR, endC;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void find_optimal_path() {
    priority_queue<Node> pq;

    pq.push({safety[startR][startC], startR, startC});
    max_min_safety[startR][startC] = safety[startR][startC];

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int d = node.safety;
        int r = node.r;
        int c = node.c;

        if (d < max_min_safety[r][c]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            int new_path_safety = min(d, safety[nr][nc]);

            if (new_path_safety > max_min_safety[nr][nc]) {
                max_min_safety[nr][nc] = new_path_safety;
                pq.push({new_path_safety, nr, nc});
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        fill(safety[i], safety[i] + M, -1);
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '+') {
                q.push({i, j});
                safety[i][j] = 0;
            } else if (grid[i][j] == 'V') {
                startR = i;
                startC = j;
            } else if (grid[i][j] == 'J') {
                endR = i;
                endC = j;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && safety[nr][nc] == -1) {
                safety[nr][nc] = safety[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    find_optimal_path();

    cout << max_min_safety[endR][endC] << "\n";

    return 0;
}