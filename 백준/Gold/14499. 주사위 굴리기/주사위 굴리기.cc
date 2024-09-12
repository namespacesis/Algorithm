#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, M;
int arr[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0};

int main() {
    FastIO;

    int x, y, K;

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

	while (K--) {
		int dir;
		cin >> dir;

		int nx = x;
		int ny = y;

		switch (dir) {
		case 1:
			ny++;
			break;
		case 2:
			ny--;
			break;
		case 3:
			nx--;
			break;
		case 4:
			nx++;
			break;
		}

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			continue;
		}

		x = nx;
		y = ny;

		int temp[6] = { 0, 0, 0, 0, 0, 0 };

		switch (dir) {
		case 1:
			temp[0] = dice[0];
			temp[1] = dice[4];
			temp[2] = dice[2];
			temp[3] = dice[5];
			temp[4] = dice[3];
			temp[5] = dice[1];
			break;
		case 2:
			temp[0] = dice[0];
			temp[1] = dice[5];
			temp[2] = dice[2];
			temp[3] = dice[4];
			temp[4] = dice[1];
			temp[5] = dice[3];
			break;
		case 3:
			temp[0] = dice[1];
			temp[1] = dice[2];
			temp[2] = dice[3];
			temp[3] = dice[0];
			temp[4] = dice[4];
			temp[5] = dice[5];
			break;
		case 4:
			temp[0] = dice[3];
			temp[1] = dice[0];
			temp[2] = dice[1];
			temp[3] = dice[2];
			temp[4] = dice[4];
			temp[5] = dice[5];
			break;
		}

		for (int i = 0; i < 6; i++) {
			dice[i] = temp[i];
		}

		if (arr[x][y] == 0) {
			arr[x][y] = dice[3];
		}
		else {
			dice[3] = arr[x][y];
			arr[x][y] = 0;
		}

		cout << dice[1] << "\n";
	}

	return 0;
}
