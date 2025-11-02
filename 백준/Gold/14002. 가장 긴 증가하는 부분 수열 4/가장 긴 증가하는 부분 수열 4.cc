#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int arr[1000];
int dp[1000];
int prev_idx[1000];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		dp[i] = 1;
		prev_idx[i] = -1;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				prev_idx[i] = j;
			}
		}
	}

	int res = 0;
	int max_idx = 0;
	for (int i = 0; i < N; ++i) {
		if (res < dp[i]) {
			res = dp[i];
			max_idx = i;
		}
	}

	cout << res << endl;

	stack<int> lis;
	int current_idx = max_idx;

	while (current_idx != -1) {
		lis.push(arr[current_idx]);
		current_idx = prev_idx[current_idx];
	}

	while (!lis.empty()) {
		cout << lis.top() << " ";
		lis.pop();
	}
	cout << endl;

	return 0;
}