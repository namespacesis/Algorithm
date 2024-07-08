#include <iostream>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int arr[10][10];
int paper[6];
int res = 1e9;

int check(int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (!arr[x + i][y + j]) {
                return 0;
            }
        }
    }

    return 1;
}

void change(int x, int y, int k, int val) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			arr[x + i][y + j] = val;
		}
	}
}

void dfs(int x, int y, int cnt) {
	while (!arr[x][y]) {
		if (++y == 10) {
			x++;
			y = 0;
		}

		if (x == 10) {
			res = min(res, cnt);
			return;
		}
	}

	if (res <= cnt) {
		return;
	}

	for (int k = 5; k >= 1; k--) {
		if (paper[k] == 5) {
			continue;
		}

		if (x + k > 10 || y + k > 10) {
			continue;
		}

		if (!check(x, y, k)) {
			continue;
		}

		change(x, y, k, 0);
		paper[k]++;
		dfs(x, y, cnt + 1);
		change(x, y, k, 1);
		paper[k]--;
	}
}

int main() {
    FastIO;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);

	if (res == 1e9) {
		cout << -1 << "\n";
	}
	else {
		cout << res << "\n";
	}

	return 0;
}
