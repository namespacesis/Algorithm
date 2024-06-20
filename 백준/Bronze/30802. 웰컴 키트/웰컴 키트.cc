#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N;
int arr[6];
int T, P;
int res1 = 0, res2, res3;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        if (arr[i] % T != 0) {
            res1 += (arr[i] / T) + 1;
        }
        else res1 += (arr[i] / T);
    }

    res2 = N / P;
    res3 = N % P;

    cout << res1 << "\n";

    cout << res2 << " " << res3 << "\n";

    return 0;
}
