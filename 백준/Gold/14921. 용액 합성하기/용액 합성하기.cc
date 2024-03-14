#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[100000];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;

	int temp = abs(arr[left] + arr[right]);
	res = arr[left] + arr[right];

	while (left < right) {
		int sumVal = arr[left] + arr[right];
		if (abs(sumVal) < temp) {
			temp = abs(sumVal);
			res = sumVal;
		}
		if (sumVal < 0) left++;
		else right--;
	}

	cout << res << "\n";
	return 0;
}