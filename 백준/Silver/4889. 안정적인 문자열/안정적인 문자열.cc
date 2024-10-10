#include <iostream>
#include <vector>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int main() {
    FastIO;

    string s;
    int tc = 1;

    while (true) {
        getline(cin, s);

        if (s[0] == '-') break;

        int res = 0;

        vector<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                stack.push_back('{');
            }
            else {
				if (stack.empty()) {
					stack.push_back('{');
					res++;
				} else {
					stack.pop_back();
				}
			}
        }

        if (!stack.empty()) {
            res += stack.size() / 2;
        }

        cout << tc << ". " << res << "\n";

        tc++;
    }

    return 0;
}
