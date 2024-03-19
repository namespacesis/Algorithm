#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	arr = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	long temp = 2000000000;
	int res1;
	int res2;
	int left = 0;
	int right = N - 1;

	while (left < right) {
		if (abs(arr[left] + arr[right]) < temp) {
			temp = abs(arr[left] + arr[right]);
			res1 = arr[left];
			res2 = arr[right];
			
		}
		if (arr[left] + arr[right] < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << res1 << " " << res2 << "\n";

	return 0;
}