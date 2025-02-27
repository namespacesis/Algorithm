#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
string arr[9];
bool visited[9];
int res;

void dfs(int cnt, int l, string s) {
    if (cnt == N) {
        res = min(res, l);
    }

    if (l > res) return;

    for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;

        int sLen = s.length();
        int aLen = arr[i].length();
        int k = min(sLen, aLen);

        int temp = l + aLen;
        int maxK = 0;
        for (int j = 0; j < k; j++) {
            bool flag = false;
            for (int z = 0; z < j + 1; z++) {
                if (s[sLen - 1 - j + z] != arr[i][z]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                maxK = j + 1;
            }
        }
		dfs(cnt + 1, temp - maxK, s.substr(0, sLen - maxK) + arr[i]);
		visited[i] = false;
	}
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    res = 90;

    dfs(0, 0, "");

    cout << res << endl;

    return 0;
}