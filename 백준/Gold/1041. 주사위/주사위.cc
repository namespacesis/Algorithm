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

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    int m1 = min(arr[0], arr[5]);
    int m2 = min(arr[1], arr[4]);
    int m3 = min(arr[2], arr[3]);

    int min1 = min(m1, min(m2, m3));
    int min2 = min(m1 + m2, min(m1 + m3, m2 + m3));
    int min3 = m1 + m2 + m3;
    
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
