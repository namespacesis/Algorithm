#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int r1, c1;
    int r2, c2;
    int life;
    string path;
};

int T;
int M, N;
char arr[50][50];
bool visited[50][50][50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int r1, c1, r2, c2;

string bfs() {
    queue<Node> q;
    q.push({r1, c1, r2, c2, 5, ""});
    visited[r1][c1][r2][c2] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.r1 == cur.r2 && cur.c1 == cur.c2) {
            return cur.path;
        }

        for (int i = 0; i < 4; i++) {
            string npath = cur.path;
            if (i == 0) npath += 'E';
			else if (i == 1) npath += 'W';
			else if (i == 2) npath += 'S';
			else npath += 'N';

            int nlife = cur.life;

            int nr1 = cur.r1 + dx[i];
			int nc1 = cur.c1 + dy[i];
			int nr2 = cur.r2 + dx[i];
			int nc2 = cur.c2 + dy[i];

			if (nr1 < 0) nr1 = M - 1;
            if (nr1 >= M) nr1 = 0;
            if (nc1 < 0) nc1 = N - 1;
            if (nc1 >= N) nc1 = 0;

            if (nr2 < 0) nr2 = M - 1;
            if (nr2 >= M) nr2 = 0;
            if (nc2 < 0) nc2 = N - 1;
            if (nc2 >= N) nc2 = 0;

            if (arr[nr1][nc1] == 'X') {
                nr1 = cur.r1;
                nc1 = cur.c1;
            }

            if (arr[nr2][nc2] == 'X') {
				nr2 = cur.r2;
				nc2 = cur.c2;
			}

            if (arr[nr1][nc1] == 'G') {
                continue;
            }

            if (arr[nr2][nc2] == 'G') {
                continue;
            }

			if (visited[nr1][nc1][nr2][nc2]) {
				continue;
			}

			visited[nr1][nc1][nr2][nc2] = true;
			q.push({nr1, nc1, nr2, nc2, nlife, npath});
        }
    }

    return "IMPOSSIBLE";
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        memset(visited, false, sizeof(visited));

        cin >> M >> N;

        r1 = c1 = r2 = c2 = -1;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];

                if (arr[i][j] == 'P') {
                    if (r1 != -1 && c1 != -1) {
                        r2 = i;
                        c2 = j;
                    }
                    else {
						r1 = i;
						c1 = j;
					}
                }
            }
        }

        string ret = bfs();

        if (ret == "IMPOSSIBLE") {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << ret.size() << " " << ret << endl;
		}
    }

    return 0;
}