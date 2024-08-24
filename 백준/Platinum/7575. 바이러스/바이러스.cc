#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N, K;
vector<int> arr[100];

vector<int> getPi(const vector<int>& pattern) {
    int M = pattern.size();
    vector<int> pi(M, 0);
    int j = 0;

    for (int i = 1; i < M; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
    
    return pi;
}

bool kmp(int idx, const vector<int>& pattern) {
    vector<int> text = arr[idx];
    vector<int> pi = getPi(pattern);
    int N = text.size();
    int M = pattern.size();
    int j = 0;

    for (int i = 0; i < N; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (text[i] == pattern[j]) {
			if (j == M - 1) {
				return true;
			} else {
				j++;
			}
		}
	}

    return false;
}

bool check() {
    const vector<int>& first = arr[0];
    int M = first.size();

    for (int i = 0; i <= M - K; i++) {
        vector<int> temp(first.begin() + i, first.begin() + i + K);
        vector<int> tempRev = temp;
        reverse(tempRev.begin(), tempRev.end());

        bool found = true;

        for (int j = 1; j < N; j++) {
            if (!kmp(j, temp) && !kmp(j, tempRev)) {
				found = false;
				break;
			}
        }

        if (found) {
			return true;
		}
    }

    return false;
}

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;

        arr[i].resize(M);

        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cout << (check() ? "YES" : "NO") << "\n";

    return 0;
}
