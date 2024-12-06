#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
int K;

int main() {
    FastIO;

    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> diff(N - 1);

    for (int i = 0; i < N - 1; i++) {
        diff[i] = arr[i + 1] - arr[i];
    }

    sort(diff.begin(), diff.end());

    int res = 0;

    for (int i = 0; i < N - K; i++) {
		res += diff[i];
	}

    cout << res << endl;

    return 0;
}
