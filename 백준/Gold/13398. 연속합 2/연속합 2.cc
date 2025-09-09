#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int n;
int arr[100000];
int Lsum[100000];
int Rsum[100000];

int main() {
    FastIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = arr[0];

    Lsum[0] = arr[0];
    Rsum[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        Lsum[i] = max(arr[i], Lsum[i - 1] + arr[i]);
        res = max(res, Lsum[i]);
    }

    for (int i = n - 2; i > 0; i--) {
        Rsum[i] = max(arr[i], Rsum[i + 1] + arr[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        res = max(res, Lsum[i - 1] + Rsum[i + 1]);
    }

    cout << res << endl;

    return 0;
}