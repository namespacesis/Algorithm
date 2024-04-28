#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

string num_list[15];
int ten_mod_k[51], mod_k[15];
ll d[1 << 15][100];

ll gcd(ll a, ll b) {
	ll c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num_list[i];
	}

	cin >> k;

	ten_mod_k[0] = 1 % k;

	for (int i = 1; i <= 50; i++) {
		ten_mod_k[i] = (ten_mod_k[i - 1] * 10) % k;
	}

	ll total = 1;

	for (int i = 0; i < n; i++) {
		int x = 0;
		total *= i + 1;

		for (int j = 0; j < num_list[i].size(); j++) {
			x = x * 10 + (num_list[i][j] - '0');
			x = x % k;
		}

		d[1 << i][x] = 1;
		mod_k[i] = x;
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) == 0) {
				int a = (i | (1 << j));
				for (int m = 0; m < k; m++) {
					int b = (m * ten_mod_k[num_list[j].size()]) + mod_k[j];
					b = b % k;

					d[a][b] += d[i][m];
				}
			}
		}
	}

	ll possible = d[(1 << n) - 1][0];

	if (possible == 0) {
		cout << "0/1" << endl;
	}
	else if (possible == total) {
		cout << "1/1" << endl;
	}
	else {
		ll g = gcd(total, possible);
		cout << possible / g << "/" << total / g << endl;
	}

	return 0;
}