#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int T;
int arr[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> res;

struct Node {
    int x;
    int y;
};

int bfs(int x, int y) {
    queue<Node> q;
    arr[x][y] = 1;
    q.push({ x, y });

    int res = 0;

    if (x % 2 == 1 && y % 2 == 1) {
		res++;
	}

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx <= 0 || nx >= N * 2 || ny <= 0 || ny >= M * 2) {
				continue;
			}

            if (arr[nx][ny] == 0) {
				arr[nx][ny] = 1;
                if (nx % 2 == 1 && ny % 2 == 1) {
                    res++;
                }
                q.push({ nx, ny });
			}
        }
    }

    return res;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i <= N * 2; i++) {
        arr[i][0] = 1;
        arr[i][M * 2] = 1;
        arr[0][i] = 1;
        arr[N * 2][i] = 1;
    }

    cin >> T;

    int Sx, Sy, Ex, Ey;

    for (int i = 0; i < T; i++) {
        cin >> Sx >> Sy >> Ex >> Ey;

        Sx = Sx * 2;
        Sy = Sy * 2;
        Ex = Ex * 2;
        Ey = Ey * 2;

        if (Sx > Ex) {
			swap(Sx, Ex);
		}

        if (Sy > Ey) {
            swap(Sy, Ey);
        }

        for (int j = Sx; j <= Ex; j++) {
			arr[j][Sy] = 1;
			arr[j][Ey] = 1;
		}

        for (int j = Sy; j <= Ey; j++) {
            arr[Sx][j] = 1;
            arr[Ex][j] = 1;
        }
    }

    for (int i = 1; i < N * 2; i++) {
        for (int j = 1; j < M * 2; j++) {
            if (arr[i][j] == 0) {
                int cnt = bfs(i, j);
                res.push_back(cnt);
            }
        }
    }

    sort(res.begin(), res.end(), greater());

    cout << res[0] << "\n";
    cout << res[res.size() - 1] << "\n";

    return 0;
}
