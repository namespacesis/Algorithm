#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N, M;
int arr[50][50];
int arr2[50][50];

void flip(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            arr[i][j] = 1 - arr[i][j];
        }
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr2[i][j] = s[j] - '0';
		}
	}

    int res = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (arr[i][j] != arr2[i][j]) {
                flip(i, j);
                res++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != arr2[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

    cout << res << endl;

    return 0;
}
