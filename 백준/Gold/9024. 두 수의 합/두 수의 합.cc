#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N, K;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;

		arr = vector<int>(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		long temp = 2000000000;
		int res = 0;
		int left = 0;
		int right = N - 1;

		while (left < right) {
			if (abs(arr[left] + arr[right] - K) <= temp) {
				if (abs(arr[left] + arr[right] - K) < temp) {
					res = 1;
				}
				else if (abs(arr[left] + arr[right] - K) == temp) {
					res++;
				}
				temp = abs(arr[left] + arr[right] - K);
			}
			if (arr[left] + arr[right] < K) {
				left++;
			}
			else {
				right--;
			}
		}

		cout << res << "\n";
	}
	
	return 0;
}