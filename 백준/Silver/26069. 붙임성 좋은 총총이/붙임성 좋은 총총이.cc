#include <iostream>
#include <string>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
unordered_map<string, bool> um;

int main() {
	FastIO;

	cin >> N;

	int res = 1;

	um["ChongChong"] = true;

	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;

		if ((um[A] && !um[B]) || (!um[A] && um[B])) {
			um[A] = true;
			um[B] = true;
			res++;
		}
	}
	
	cout << res << "\n";

	return 0;
}
