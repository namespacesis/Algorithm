#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N, L;
int arr[100][100];

bool canPlaceSlope(const int* line) {
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        int diff = line[i] - line[i - 1];

        if (diff == 0) {
            cnt++;
        }
        else if (diff == 1) {
            if (cnt >= L) {
                cnt = 1;
            }
            else {
                return false;
            }
        }
        else if (diff == -1) {
            for (int j = i; j < i + L; j++) {
                if (j >= N || line[j] != line[i]) return false;
            }
            i += L - 1;
            cnt = 0;
        }
        else {
            return false;
        }
    }
    return true;
}

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
        if (canPlaceSlope(arr[i])) res++;
    }

    for (int i = 0; i < N; i++) {
        int col[100]{};

        for (int j = 0; j < N; j++) {
            col[j] = arr[j][i];
        }

        if (canPlaceSlope(col)) res++;
    }

    cout << res << endl;

    return 0;
}
