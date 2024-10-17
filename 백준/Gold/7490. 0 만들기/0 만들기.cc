#include <iostream>
#include <string>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;
int N;
vector<string> res;

int cal(string s) {
    int res = 0;
    int temp = 0;
    char c = '+';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            if (c == '+') res += temp;
            else if (c == '-') res -= temp;
            c = '+';
        }
        else if (s[i] == '-') {
            if (c == '+') res += temp;
            else if (c == '-') res -= temp;
            c = '-';
        }
        else if (s[i] == ' ') {
            temp = temp * 10 + s[i + 1] - '0';
            i++;
        }
        else {
            temp = s[i] - '0';
        }
    }
    
    if (c == '+') res += temp;
	else if (c == '-') res -= temp;

    return res;
}

void dfs(int n, string s) {
    if (n == N + 1) {
        if (cal(s) == 0) {
            res.push_back(s);
        }
        return;
    }

    dfs(n + 1, s + " " + to_string(n));
    dfs(n + 1, s + "+" + to_string(n));
    dfs(n + 1, s + "-" + to_string(n));
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> N;

        dfs(2, "1");
    }

    int len = res[0].size();

    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > len) {
            cout << "\n";
            len = res[i].size();
        }
		cout << res[i] << "\n";
	}

    return 0;
}