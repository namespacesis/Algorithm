#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;
int N, K;
int arr[10000];
vector<int> res;

int binarySearch(int n) {
    int left = 0;
    int right = res.size() - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (res[mid] >= n) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    FastIO;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        res.clear();
        cin >> N >> K;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        res.push_back(arr[0]);

        for (int i = 1; i < N; i++) {
            if (arr[i] > res.back()) {
                res.push_back(arr[i]);
            }
            else {
                int idx = binarySearch(arr[i]);
                res[idx] = arr[i];
            }
        }

        if (res.size() < K) {
            cout << "Case #" << tc << "\n";
            cout << "0\n";
        }
        else {
            cout << "Case #" << tc << "\n";
            cout << "1\n";
        }
    }

    return 0;
}
