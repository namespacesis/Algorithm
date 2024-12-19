#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
vector<int> arrX;
vector<int> arrY;
pair<int, int> arr[100000];

int main() {
    FastIO;

    cin >> N;

    arrX.resize(N);
    arrY.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arrX[i] = x;
        arrY[i] = y;
        arr[i] = { x, y };
    }

    sort(arrX.begin(), arrX.end());
    sort(arrY.begin(), arrY.end());

    int midX = arrX[N / 2];
    int midY = arrY[N / 2];

    long long res = 0;

    for (int i = 0; i < N; i++) {
        res += abs(midX - arr[i].first);
        res += abs(midY - arr[i].second);
    }

    cout << res << endl;

    return 0;
}
