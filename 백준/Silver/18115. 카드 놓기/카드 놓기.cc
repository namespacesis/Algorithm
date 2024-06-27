#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N;

int main() {
	FastIO;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	deque<int> dq;

	int card = 1;

	for (int i = N - 1; i >= 0; i--) {

		if (v[i] == 1) {
			dq.push_back(card);
		}
		else if (v[i] == 2) {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(tmp);
		}
		else if (v[i] == 3) {
			dq.push_front(card);
		}

		card++;
	}

	for (int i = N - 1; i >= 0; i--) {
		cout << dq[i] << " ";
	}

	cout << "\n";

	return 0;
}