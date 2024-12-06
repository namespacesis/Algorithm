#include <iostream>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

long long N;
int arr[6];

int main() {
    FastIO;

    cin >> N;

    int min1 = 1000000;

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        min1 = min(min1, arr[i]);
    }

    int min2 = 1000000;

    min2 = min(min2, arr[0] + arr[1]);
    min2 = min(min2, arr[0] + arr[2]);
    min2 = min(min2, arr[0] + arr[3]);
    min2 = min(min2, arr[0] + arr[4]);
    min2 = min(min2, arr[1] + arr[2]);
    min2 = min(min2, arr[1] + arr[3]);
    min2 = min(min2, arr[1] + arr[5]);
    min2 = min(min2, arr[2] + arr[4]);
    min2 = min(min2, arr[2] + arr[5]);
    min2 = min(min2, arr[3] + arr[4]);
    min2 = min(min2, arr[3] + arr[5]);
    min2 = min(min2, arr[4] + arr[5]);

    int min3 = 1000000;

    min3 = min(min3, arr[0] + arr[1] + arr[2]);
    min3 = min(min3, arr[0] + arr[1] + arr[3]);
    min3 = min(min3, arr[0] + arr[2] + arr[4]);
    min3 = min(min3, arr[0] + arr[3] + arr[4]);
    min3 = min(min3, arr[1] + arr[2] + arr[5]);
    min3 = min(min3, arr[1] + arr[3] + arr[5]);
    min3 = min(min3, arr[2] + arr[4] + arr[5]);
    min3 = min(min3, arr[3] + arr[4] + arr[5]);

    long long res = 0;

    if (N == 1) {
        int maxN = 0;
        for (int i = 0; i < 6; i++) {
            res += arr[i];
            maxN = max(maxN, arr[i]);
        }
        res -= maxN;
    }
    else {
        res += min1 * (((N - 2) * (N - 2)) + (4 * (N - 2) * (N - 1)));
		res += min2 * (8 * N - 12);
		res += min3 * 4;
    }
    
    cout << res << endl;

    return 0;
}
