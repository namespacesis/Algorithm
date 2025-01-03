#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

struct Player {
    int x, y;
    int idx;
};

int M, N, P;
int HP;
char arr[1000][1000];
bool visited[1000][1000][26];
int dps[26];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<Player> qList[26];
int ar, ac;
bool check[26];

int main() {
    FastIO;

    cin >> M >> N >> P;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
				qList[arr[i][j] - 'a'].push({i, j, arr[i][j] - 'a'});
                arr[i][j] = '.';
			}
            if (arr[i][j] == 'B') {
                ar = i;
                ac = j;
            }
        }
    }

    for (int i = 0; i < P; i++) {
        char c;
        cin >> c;
        cin >> dps[c - 'a'];
	}

    cin >> HP;

    while (HP > 0) {
        for (int i = 0; i < P; i++) {
            if (visited[ar][ac][i]) {
                check[i] = true;
                HP -= dps[i];
                continue;
            }
            int size = qList[i].size();
            for (int j = 0; j < size; j++) {
				Player cur = qList[i].front();
				qList[i].pop();

				for (int k = 0; k < 4; k++) {
					int nx = cur.x + dx[k];
					int ny = cur.y + dy[k];

					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (visited[nx][ny][i]) continue;
					if (arr[nx][ny] == 'X') continue;

					visited[nx][ny][i] = true;
					qList[i].push({nx, ny, i});
				}
			}
        }
    }

    int res = 0;

    for (int i = 0; i < P; i++) {
        if (check[i]) res++;
    }

    cout << res << endl;

    return 0;
}
