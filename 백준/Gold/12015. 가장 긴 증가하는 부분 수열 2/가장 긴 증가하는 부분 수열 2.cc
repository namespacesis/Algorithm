#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> res;

int bs(int k) {
	int lo = 0, hi = res.size() - 1, mid;

	while (lo < hi) {
		mid = lo + (hi - lo) / 2;

		if (res[mid] >= k)
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, t, idx;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;  arr.push_back(t);
	}
	res.push_back(arr.front());

	for (int i = 1; i < n; i++) {
		if (arr[i] > res.back())
			res.push_back(arr[i]);
		else {
			idx = bs(arr[i]);
			res[idx] = arr[i];
		}
	}
	cout << res.size();

	return 0;
}