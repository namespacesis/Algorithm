#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int r, c, s, d, z;
};

int R, C, M;
int r, c, s, d, z;
vector<Shark> arr[101][101];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };
int res;

int change_direction(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) {
			s %= ((R - 1) * 2);
		}
		else if (d == 3 || d == 4) {
			s %= ((C - 1) * 2);
		}
		arr[r][c].push_back({ r, c, s, d, z });
	}
	
	int T = 0;
	while (++T <= C) {
		for (int i = 1; i <= R; i++) {
			if (!arr[i][T].empty()) {
				res += arr[i][T][0].z;
				arr[i][T].pop_back();
				break;
			}
		}
		vector<Shark> temp_arr[101][101];

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (arr[i][j].empty()) continue;
				Shark cur = arr[i][j][0];
				arr[i][j].pop_back();

				int& cr = cur.r;
				int& cc = cur.c;
				int cs = cur.s;
				int& cd = cur.d;

				while (cs--) {
					int nr = cr + dx[cd];
					int nc = cc + dy[cd];

					if (nr <= 0 || nr > R || nc <= 0 || nc > C) {
						cd = change_direction(cd);
					}

					cr += dx[cd];
					cc += dy[cd];
				}

				if (!temp_arr[cr][cc].empty()) {
					if (temp_arr[cr][cc][0].z < cur.z) {
						temp_arr[cr][cc].pop_back();
						temp_arr[cr][cc].push_back(cur);
					}
				}
				else {
					temp_arr[cr][cc].push_back(cur);
				}
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				arr[i][j] = temp_arr[i][j];
			}
		}
	}

	cout << res << "\n";
	return 0;
}