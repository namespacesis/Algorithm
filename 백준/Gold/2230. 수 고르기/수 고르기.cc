#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2e9

using namespace std;

int N, M;
vector<int> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	arr = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = 0;
	int res = INT_MAX;

	while (right < N) {
		if (arr[right] - arr[left] >= M) {
			res = min(res, arr[right] - arr[left]);
			if (res == M) break;
			left++;
		}
		else right++;
	}

	cout << res << "\n";
	return 0;
}