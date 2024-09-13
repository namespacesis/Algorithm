#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, K;
int arr[200];
bool robot[100];
int res = 0;
int cnt = 0;

void simulate() {
	while (true) {
        res++;

        int temp = arr[2 * N - 1];

        for (int i = 2 * N - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = temp;

        for (int i = N - 1; i > 0; i--) {
			robot[i] = robot[i - 1];
		}

        robot[0] = false;

		robot[N - 1] = false;

		for (int i = N - 1; i > 0; i--) {
			if (robot[i - 1] && !robot[i] && arr[i] > 0) {
				robot[i] = true;
				robot[i - 1] = false;
				arr[i]--;
				if (arr[i] == 0) cnt++;
			}
		}

		robot[N - 1] = false;

		if (arr[0] > 0) {
			robot[0] = true;
			arr[0]--;
			if (arr[0] == 0) cnt++;
		}

		if (cnt >= K) {
			cout << res << '\n';
			return;
		}
	}
}

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 0; i < N * 2; i++) {
        cin >> arr[i];
    }

    simulate();

    return 0;
}
