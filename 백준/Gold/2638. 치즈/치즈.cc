#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int arr[100][100];

pair<int, int> direction[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<vector<bool>> bfs(int i, int j) {
	vector<vector<bool>> air(N, vector<bool>(M));
	air[i][j] = true;

	queue<pair<int, int>> q;
	q.push({ i, j });

	while (!q.empty()) {
		int x, y;
		tie (x, y) = q.front();
		q.pop();
		
		for (auto[dx, dy] : direction) {
			int nx, ny;
			nx = x + dx;
			ny = y + dy;

			if (0 <= nx && nx < N && 0 <= ny && ny < M && !air[nx][ny]) {
				if (arr[nx][ny] == 0) {
					air[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return air;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
    int cheess = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
            int n;
			cin >> n;
            arr[i][j] = n;
            cheess += n;
		}
	}

	int res = 0;

	while (cheess > 0) {
		++res;

		auto air = bfs(0, 0);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] == 1) {
					int cnt = 0;
					for (auto[dx, dy] : direction) {
						int nx, ny;
						nx = i + dx;
						ny = j + dy;
						if (0 <= nx && nx < N && 0 <= ny && ny < M && air[nx][ny]) {
							++cnt;
							if (cnt >= 2) {
								arr[i][j] = 0;
                                --cheess;
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}