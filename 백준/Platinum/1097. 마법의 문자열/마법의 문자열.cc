#include <iostream>
#include <string>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
int K;
string arr[8];
bool visited[8];
vector<string> per;
int pi[160];

void makeCombination(string idx) {
	if (idx.size() == N) {
		string str = "";
		for (int i = 0; i < N; i++) {
			str += arr[idx[i] - '0'];
		}

		per.push_back(str);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			makeCombination(idx + to_string(i));
			visited[i] = false;
		}
	}
}

void getPi(string str) {
	int j = 0;

	for (int i = 1; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j]) {
			j = pi[j - 1];
		}

		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
	}
}

int kmp(string str) {
	int ret = 0;
	string pattern = str;
	str += str;

	int j = 0;

	for (int i = 0; i < str.size() - 1; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				ret++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	return ret;
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> arr[i];
    }

    cin >> K;

	int res = 0;

    makeCombination("");

	for (int i = 0; i < per.size(); i++) {
		getPi(per[i]);
		if (kmp(per[i]) == K) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}
