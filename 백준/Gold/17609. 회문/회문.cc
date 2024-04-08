#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int check(const string& s) {
    int start = 0, end = s.length() - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            if (isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1)) {
                return 1;
            }
            else {
                return 2;
            }
        }
        start++;
        end--;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    string s;

    for (int i = 0; i < T; i++) {
        cin >> s;
        cout << check(s) << "\n";
    }

    return 0;
}
