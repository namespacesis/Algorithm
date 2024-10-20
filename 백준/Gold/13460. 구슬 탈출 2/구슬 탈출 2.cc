#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int br, bc;
    int rr, rc;
    int cnt;
    int dir;
};

int N, M;
char arr[10][10];
int bx, by;
int rx, ry;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[10][10][10][10];
int res = 11;

int bfs() {
    queue<Node> q;
    for (int i = 0; i < 4; i++) {
        q.push({ bx, by, rx, ry, 0, i });
    }
    visited[bx][by][rx][ry] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        
        if (cur.cnt == 10) continue;

        int nrx = cur.rr;
        int nry = cur.rc;
        int nbx = cur.br;
        int nby = cur.bc;
        bool rflag = false;
        bool bflag = false;

        while (true) {
            if (!rflag) {
                nrx += dx[cur.dir];
                nry += dy[cur.dir];
            }
            if (!bflag) {
                nbx += dx[cur.dir];
                nby += dy[cur.dir];
            }

            if (!rflag && arr[nrx][nry] == '#') {
                nrx -= dx[cur.dir];
				nry -= dy[cur.dir];
                rflag = true;
            }
            if (!bflag && arr[nbx][nby] == '#') {
                nbx -= dx[cur.dir];
                nby -= dy[cur.dir];
                bflag = true;
            }

            if (!rflag && arr[nrx][nry] == 'O') {
                nrx = -1;
				nry = -1;
                rflag = true;
            }
            if (!bflag && arr[nbx][nby] == 'O') {
				nbx = -1;
				nby = -1;
                bflag = true;
			}

            if (rflag && bflag) break;

            if (nrx == nbx && nry == nby) {
                if (rflag) {
					nbx -= dx[cur.dir];
					nby -= dy[cur.dir];
                    bflag = true;
                    break;
				}
				else {
					nrx -= dx[cur.dir];
					nry -= dy[cur.dir];
                    rflag = true;
                    break;
				}
            }
        }

        if (nrx == -1 && nbx != -1) {
            res = min(res, cur.cnt + 1);
            continue;
        }
        else if (nbx == -1) continue;

        for (int i = 0; i < 4; i++) {
            if (cur.dir == i) continue;
            if (!visited[nbx][nby][nrx][nry]) {
                q.push({ nbx, nby, nrx, nry, cur.cnt + 1, i });
            }
        }
        visited[nbx][nby][nrx][nry] = true;
    }

    if (res == 11) return -1;
    return res;
}

int main() {
    FastIO;
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'B') {
                bx = i;
                by = j;
                arr[i][j] = '.';
            }
            if (arr[i][j] == 'R') {
				rx = i;
				ry = j;
                arr[i][j] = '.';
			}
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}