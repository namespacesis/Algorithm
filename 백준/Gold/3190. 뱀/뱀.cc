#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
int L;
int arr[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, char>> Q_dir;
queue<pair<int, int>> Q_cur;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> K;

	int ax, ay;
	for (int i = 0; i < K; i++) {
		cin >> ax >> ay;
		arr[ax][ay] = 1;
	}

	cin >> L;

	int X;
	char C;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		Q_dir.push({ X, C });
	}

	int cx = 1;
	int cy = 2;
	int cDir = 0;
	int cnt = 1;
	Q_cur.push({ 1, 1 });
	arr[1][1] = 2;

	while (true) {
		if (cx > N || cy > N || cx < 1 || cy < 1) {
			break;
		}

		if (arr[cx][cy] == 2) {
			break;
		}

		if (!Q_dir.empty()) {
			if (cnt == Q_dir.front().first) {
				if (Q_dir.front().second == 'D') {
					cDir = (cDir + 1) % 4;
				}
				else if (Q_dir.front().second == 'L') {
					cDir = (cDir + 3) % 4;
				}
				Q_dir.pop();
			}
		}

		if (arr[cx][cy] == 0) {
			Q_cur.push({ cx, cy });
			arr[Q_cur.front().first][Q_cur.front().second] = 0;
			Q_cur.pop();
		}
		else if (arr[cx][cy] == 1) {
			Q_cur.push({ cx, cy });
		}

		arr[cx][cy] = 2;

		cx += dx[cDir];
		cy += dy[cDir];

		cnt++;
	}

	cout << cnt << "\n";
	return 0;
}