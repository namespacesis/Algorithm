#include <iostream>
#include <string>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main() {
    FastIO;

    string s;

    int idx = 0;
    int num = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s;

        if (s != "FizzBuzz" && s != "Fizz" && s != "Buzz") {
            idx = i;
            num = stoi(s);
        }
    }

    num += (3 - idx);

    string res;

    if (num % 5 == 0 && num % 3 == 0) {
        res = "FizzBuzz";
    }
    else if (num % 3 == 0) {
        res = "Fizz";
    }
    else if (num % 5 == 0) {
        res = "Buzz";
    }
    else {
        cout << num << "\n";
        return 0;
    }

    cout << res << "\n";

    return 0;
}
