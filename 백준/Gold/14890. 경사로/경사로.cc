#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, L;
int arr[100][100];

int main() {
    FastIO;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        int v = arr[i][0];

        int cnt = 1;

        for (int j = 1; j < N; j++) {
            int diff = arr[i][j] - v;

            if (diff == 0) {
                cnt++;
            }
            else if (diff == 1) {
                if (cnt >= L) {
                    cnt = 1;
                    v = arr[i][j];
                }
                else {
                    cnt = -1;
                    break;
                }
            }
            else if (diff == -1) {
                for (int k = 0; k < L; k++) {
                    if (j + k >= N || arr[i][j + k] != arr[i][j]) {
                        cnt = -1;
                        break;
                    }
                }

                if (cnt == -1) {
					break;
				}
                j += L - 1;
                v = arr[i][j];
                cnt = 0;
            }
            else {
                cnt = -1;
                break;
            }
        }

        if (cnt != -1) {
            res++;
        }
    }

    for (int i = 0; i < N; i++) {
        int v = arr[0][i];

        int cnt = 1;

        for (int j = 1; j < N; j++) {
            int diff = arr[j][i] - v;

            if (diff == 0) {
                cnt++;
            }
            else if (diff == 1) {
                if (cnt >= L) {
                    cnt = 1;
                    v = arr[j][i];
                }
                else {
                    cnt = -1;
                    break;
                }
            }
            else if (diff == -1) {
                for (int k = 0; k < L; k++) {
                    if (j + k >= N || arr[j + k][i] != arr[j][i]) {
                        cnt = -1;
                        break;
                    }
                }

                if (cnt == -1) {
                    break;
                }
                j += L - 1;
                v = arr[j][i];
                cnt = 0;
            }
            else {
                cnt = -1;
                break;
            }
        }

        if (cnt != -1) {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
