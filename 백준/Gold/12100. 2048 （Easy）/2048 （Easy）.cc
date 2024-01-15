#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int N;
int arr[20][20];
int res;

void move(int map[20][20]) {
	for (int i = 0; i < N; i++) {
		deque<int> dq;
		bool merge = false;
		
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				if (!dq.empty() && dq.back() == map[i][j] && !merge) {
					dq.pop_back();
					dq.push_back(map[i][j] * 2);
					merge = true;
				}
				else {
					dq.push_back(map[i][j]);
					merge = false;
				}
				map[i][j] = 0;
			}
		}

		int idx = 0;
		
		while (!dq.empty()) {
			map[i][idx++] = dq.front();
			dq.pop_front();
		}
	}
}

void rotate(int map[20][20]) {
	int temp[20][20];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[j][N - 1 - i] = map[i][j];
		}
	}
	memcpy(arr, temp, sizeof(temp));
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (res < arr[i][j]) {
					res = arr[i][j];
				}
			}
		}
		return;
	}

	int temp[20][20];

	for (int i = 0; i < 4; i++) {
		memcpy(temp, arr, sizeof(arr));
		move(arr);
		dfs(cnt + 1);
		memcpy(arr, temp, sizeof(arr));
		rotate(arr);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << res << "\n";
	return 0;
}