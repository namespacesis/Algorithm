#include <iostream>
#include <unordered_map>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;
using ll = long long;

int N;
unordered_map<ll, int> um;
set<ll> s;

int main() {
	FastIO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		ll num;
		cin >> num;
		s.insert(num);
		um[num]++;
	}

	int cnt = 0;

	ll res;

	for (auto& iter : s) {
		if (um[iter] > cnt) {
			cnt = um[iter];
			res = iter;
		}
	}

	cout << res << "\n";

	return 0;
}
