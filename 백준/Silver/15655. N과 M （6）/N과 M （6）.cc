#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> com;

void func(int M, int idx) {
	if (M == 0) {
		for (int n : com) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		com.push_back(arr[i]);
		func(M - 1, i + 1);
		com.pop_back();
	}

}

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

	func(M, 0);
	return 0;
}