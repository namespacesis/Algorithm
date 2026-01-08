#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M, R;
int arr[100][100];
int arr2[100][100];

void calc(int cmd, int id) {
    int hn = N / 2;
    int hm = M / 2;

    switch (cmd) {
        case 1:
            for (int i = N - 1; i >= 0; --i) {
                for (int j = 0; j < M; ++j) {
                    if (id == 0) {
                        arr2[(N - 1) - i][j] = arr[i][j];
                    }
                    else {
                        arr[(N - 1) - i][j] = arr2[i][j];
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < N; ++i) {
                for (int j = M - 1; j >= 0; --j) {
                    if (id == 0) {
                        arr2[i][(M - 1) - j] = arr[i][j];
                    }
                    else {
                        arr[i][(M - 1) - j] = arr2[i][j];
                    }
                }
            }
            break;
        case 3:
            for (int j = 0; j < M; ++j) {
                for (int i = N - 1; i >= 0; --i) {
                    if (id == 0) {
                        arr2[j][(N - 1) - i] = arr[i][j];
                    }
                    else {
                        arr[j][(N - 1) - i] = arr2[i][j];
                    }
                }
            }
            swap(N, M);
            break;
        case 4:
            for (int j = M - 1; j >= 0; --j) {
                for (int i = 0; i < N; ++i) {
                    if (id == 0) {
                        arr2[(M - 1) - j][i] = arr[i][j];
                    }
                    else {
                        arr[(M - 1) - j][i] = arr2[i][j];
                    }
                }
            }
            swap(N, M);
            break;
        case 5:
            for (int i = 0; i < hn; i++) {
                for (int j = 0; j < hm; j++) {
                    if (id == 0) {
                        arr2[i][j + hm] = arr[i][j];
                        arr2[i + hn][j + hm] = arr[i][j + hm];
                        arr2[i + hn][j] = arr[i + hn][j + hm];
                        arr2[i][j] = arr[i + hn][j];
                    } else {
                        arr[i][j + hm] = arr2[i][j];
                        arr[i + hn][j + hm] = arr2[i][j + hm];
                        arr[i + hn][j] = arr2[i + hn][j + hm];
                        arr[i][j] = arr2[i + hn][j];
                    }
                }
            }
            break;
        case 6:
            for (int i = 0; i < hn; i++) {
                for (int j = 0; j < hm; j++) {
                    if (id == 0) {
                        arr2[i + hn][j] = arr[i][j];
                        arr2[i + hn][j + hm] = arr[i + hn][j];
                        arr2[i][j + hm] = arr[i + hn][j + hm];
                        arr2[i][j] = arr[i][j + hm];
                    } else {
                        arr[i + hn][j] = arr2[i][j];
                        arr[i + hn][j + hm] = arr2[i + hn][j];
                        arr[i][j + hm] = arr2[i + hn][j + hm];
                        arr[i][j] = arr2[i][j + hm];
                    }
                }
            }
            break;
    }
}

int main() {
    FastIO;

    cin >> N >> M >> R;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    int cmd;

    for (int i = 0; i < R; ++i) {
        cin >> cmd;
        calc(cmd, i % 2);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (R % 2 == 0) {
                cout << arr[i][j] << " ";
            }
            else {
                cout << arr2[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}