#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N;
int arr[100000];

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, greater<int>());

    int res = 0;
    for (int i = 0; i < N; i++) {
        res = max(res, arr[i] * (i + 1));
    }

    cout << res << endl;

    return 0;
}