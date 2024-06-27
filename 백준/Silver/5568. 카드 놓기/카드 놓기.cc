#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n, k;
vector<int> v;
set<string> s;

int main() {
	FastIO;
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	do {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	
	cout << s.size() << "\n";

	return 0;
}