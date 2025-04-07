#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, M, H;
int visited[31][11];
int res = -1;

bool checkValid() {
	for (int i = 1; i <= N; i++) {
		int pos = i;
		for (int j = 1; j <= H; j++) {
			if (visited[j][pos] == 1) {
				pos++;
			} else if (visited[j][pos] == -1) {
				pos--;
			}
		}
		if (pos != i) return false;
	}
	return true;
}

void backTracking(int cnt, int x, int y) {
    if (res != -1 && cnt >= res) return;

    if (checkValid()) {
        res = cnt;
		return;
	}

    if (cnt == 3) {
        return;
    }

    for (int i = x; i <= H; i++) {
		int start_j = (i == x ? y : 1);
		for (int j = start_j; j < N; j++) {
			if (visited[i][j] == 0 && visited[i][j + 1] == 0) {
				visited[i][j] = 1;
				visited[i][j + 1] = -1;

				backTracking(cnt + 1, i, j);

				visited[i][j] = 0;
				visited[i][j + 1] = 0;
			}
		}
	}
}

int main() {
    FastIO;

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        visited[a][b] = 1;
        visited[a][b + 1] = -1;
    }

    backTracking(0, 1, 1);

	cout << res << endl;

	return 0;
}
