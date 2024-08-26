#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

string s;
string t;

int main() {
    FastIO;
    
    getline(cin, s);
    getline(cin, t);

    int s_len = s.size();
    int t_len = t.size();

    string s1 = "";
    string t1 = "";

    for (int i = 0; i < s_len; i++) {
        t1 += t;
	}

    for (int j = 0; j < t_len; j++) {
        s1 += s;
    }

    int res = s1.compare(t1);

    cout << (res == 0 ? 1 : 0) << "\n";

    return 0;
}
