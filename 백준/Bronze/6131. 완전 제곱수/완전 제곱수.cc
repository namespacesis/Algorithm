#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;

int main() {
	FastIO;

	cin >> N;

	int res = 0;

	for (int i = 1; i <= 500; i++) {
		for (int j = i; j >= 1; j--) {
			if (((i*i) - (j*j)) == N) {
				res++;
			}
		}
	}

	cout << res << endl;

	return 0;
}