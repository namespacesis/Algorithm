#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	vector<int> arr;

	int n;
	cin >> n;
	arr.push_back(n);

	for (int i = 1; i < N; i++) {
		cin >> n;

		if (n > arr.back()) {
			arr.push_back(n);
		}
		else {
			*lower_bound(arr.begin(), arr.end(), n) = n;
		}
	}

	int res = arr.size();

	cout << res << "\n";
	
	return 0;
}