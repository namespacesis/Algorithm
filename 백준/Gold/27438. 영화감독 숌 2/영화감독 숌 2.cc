#include <iostream>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

using i64 = long long;

i64 T[19]{ 1 }, DB[20]{ 0, 0, 0, 1, 19, 280, 3700, 45991, 549739, 6394870, 72915400, 818740081, 9082453159, 99766977760, 1087013539000, 11762766729271, 126545925214279, 1354561349342950, 14435830371578500, 153252438815221561 };

string findEndOfWorldNumber(int i, int j, i64 n) {
    if (i <= 3) {
        for (i64 val = 0; val < T[i]; val++) {
            string res = to_string(val);
            string cur = string(j, '6') + string(i - res.size(), '0') + res;
            if (cur.find("666") != string::npos) n--;
            if (!n) return cur.substr(j);
        }
    }
    if (j == 3) {
        string res = to_string(n - 1);
        return string(i - res.size(), '0') + res;
    }
    for (int c = 0; c < 10; c++) {
        i64 cnt = [&]() -> i64 {
            if (c != 6) return DB[i - 1];
            if (j == 0) return T[i - 3] + 9 * DB[i - 3] + 9 * DB[i - 2];
            if (j == 1) return T[i - 2] + 9 * DB[i - 2];
            if (j == 2) return T[i - 1];
            }();
        if (n <= cnt) return string(1, c + '0') + findEndOfWorldNumber(i - 1, c == 6 ? j + 1 : 0, n);
        n -= cnt;
    }
}

int main() {
    FastIO;

    i64 n;
    cin >> n;

    for (int i = 1; i < 19; i++) T[i] = T[i - 1] * 10;

    auto res = findEndOfWorldNumber(20, 0, n);

    while (res[0] == '0') res.erase(res.begin());

    cout << res << "\n";

    return 0;
}
