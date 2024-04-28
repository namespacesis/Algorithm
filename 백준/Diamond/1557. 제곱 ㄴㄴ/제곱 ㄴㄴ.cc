#include <algorithm>
#include <cmath>
#include <iostream>
#define MAX 42000

using namespace std;

int arr[MAX] = { 0 };

long long mertens(long long k) {
    long long cnt = 0;
    for (long long i = 1; i * i <= k; i++) {
        cnt += arr[i] * k / (i * i);
    }
    return cnt;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);

    long long k;
    cin >> k;

    arr[1] = 1;
    for (int i = 1; i <= MAX; i++) {
        for (int j = 2 * i; j <= MAX; j += i) {
			arr[j] -= arr[i];
        }
    }

    long long first = 0;
    long long last = 2 * k;

    while (first < last - 1) {
        long long mid = (first + last) / 2;
        if (mertens(mid) < k) first = mid;
        else last = mid;
    }

    cout << last << "\n";
    return 0;
}