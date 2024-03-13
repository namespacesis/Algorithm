#include <iostream>
#include <algorithm>

using namespace std;

int T;
int x;
int n;
int arr[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> x >> n) {
		int len = x * 10000000;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		
		int left = 0;
		int right = n - 1;
		bool check = false;

		while (left < right) {
			if (arr[left] + arr[right] == len) {
				cout << "yes " << arr[left] << " " << arr[right] << "\n";
				check = true;
				break;
			}
			else if (arr[left] + arr[right] < len) left++;
			else if (arr[left] + arr[right] > len) right--;
		}
		if (!check) {
			cout << "danger" << "\n";
		}
	}
	return 0;
}