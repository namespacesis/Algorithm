#include <iostream>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct Chess {
    int x, y, cnt, next, type;
};

int N;
int arr[10][10];
bool visited[10][10][101][3];
int kignhtDx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kignhtDy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int bishopDx[4] = {1, 1, -1, -1};
int bishopDy[4] = {1, -1, -1, 1};
int rookDx[4] = {1, 0, -1, 0};
int rookDy[4] = {0, 1, 0, -1};
const int KIGHT = 0, BISHOP = 1, ROOK = 2;

int bfs(int x, int y) {
    queue<Chess> q;
    q.push({x, y, 0, 2, KIGHT});
    q.push({x, y, 0, 2, BISHOP});
    q.push({x, y, 0, 2, ROOK});

    visited[x][y][2][KIGHT] = true;
    visited[x][y][2][BISHOP] = true;
    visited[x][y][2][ROOK] = true;

    int res = 1e9;

    while (!q.empty()) {
        Chess cur = q.front();
        q.pop();

        if (cur.next == N * N + 1) {
            res = min(res, cur.cnt);
        }

        for (int i = 0; i < 3; i++) {
            if (i == cur.type) continue;

            if (visited[cur.x][cur.y][cur.next][i]) continue;

            visited[cur.x][cur.y][cur.next][i] = true;
            q.push({ cur.x, cur.y, cur.cnt + 1, cur.next, i });
        }

        if (cur.type == KIGHT) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.x + kignhtDx[i];
                int ny = cur.y + kignhtDy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (visited[nx][ny][cur.next][KIGHT]) continue;
                visited[nx][ny][cur.next][KIGHT] = true;

                if (arr[nx][ny] == cur.next) {
                    q.push({ nx, ny, cur.cnt + 1, cur.next + 1, KIGHT });
                }
                else {
					q.push({ nx, ny, cur.cnt + 1, cur.next, KIGHT });
                }
            }
        }
        else if (cur.type == BISHOP) {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < N; j++) {
					int nx = cur.x + bishopDx[i] * j;
					int ny = cur.y + bishopDy[i] * j;

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;

                    if (visited[nx][ny][cur.next][BISHOP]) continue;
                    visited[nx][ny][cur.next][BISHOP] = true;

					if (arr[nx][ny] == cur.next) {
						q.push({ nx, ny, cur.cnt + 1, cur.next + 1, BISHOP });
						break;
					}
					else {
						q.push({ nx, ny, cur.cnt + 1, cur.next, BISHOP });
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < N; j++) {
					int nx = cur.x + rookDx[i] * j;
					int ny = cur.y + rookDy[i] * j;

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;

                    if (visited[nx][ny][cur.next][ROOK]) continue;
                    visited[nx][ny][cur.next][ROOK] = true;

					if (arr[nx][ny] == cur.next) {
						q.push({ nx, ny, cur.cnt + 1, cur.next + 1, ROOK });
						break;
					}
					else {
						q.push({ nx, ny, cur.cnt + 1, cur.next, ROOK });
					}
				}
			}
		}
    }

    return res;
}

int main() {
    FastIO;

    cin >> N;

    int s, e;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                s = i, e = j;
            }
        }
    }

    int res = bfs(s, e);

    cout << res << "\n";
    
    return 0;
}
