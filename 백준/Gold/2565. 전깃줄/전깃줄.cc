#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

struct Line {
	int L;
	int R;
};

Line arr[100];
int dp[100];

bool cmp(Line A, Line B) {
	if (A.L < B.L) return true;
	return false;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i].L >> arr[i].R;
	}

	sort(arr, arr + N, cmp);

	int ret = 0;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j].R < arr[i].R && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		ret = max(ret, dp[i]);
	}

	cout << N - ret << endl;

	return 0;
}