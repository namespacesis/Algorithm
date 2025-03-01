#include <iostream>
#include <algorithm>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int L, C;
char arr[15];
vector<string> res;

void dfs(int cnt, string str, int idx) {
    if (cnt == L) {
		int a = 0, b = 0;
		for (int i = 0; i < L; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				a++;
			} else {
				b++;
			}
		}

		if (a >= 1 && b >= 2) {
			res.push_back(str);
		}
		return;
	}

	for (int i = idx; i < C; i++) {
		dfs(cnt + 1, str + arr[i], i + 1);
	}
}

int main() {
    FastIO;

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + C);

    dfs(0, "", 0);

	for (auto s : res) {
		cout << s << endl;
	}

	return 0;
}