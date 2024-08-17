#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string str;
string password;
int arr[200];
int res = 0;

int main() {
	FastIO;

	cin >> str;

	cin >> password;
	
	int len = str.length();

	for (int i = 0; i < len; i++) {
		int idx = str[i] - '!';
		arr[idx] = i + 1;
	}

	for (int i = 0; i < password.length(); i++) {
		int idx = password[i] - '!';

		res *= len;
		res += arr[idx];
		res %= 900528;
	}

	cout << res << "\n";

	return 0;
}
