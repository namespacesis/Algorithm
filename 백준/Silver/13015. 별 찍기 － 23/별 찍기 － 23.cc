#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int N;

void top(int x) {
    string s = "";
    for (int i = 0; i < x; i++) {
        s = "";
        for (int j = 0; j < i + 1; j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < x; j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < ((x - i - 1) * 2) + 1; j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < x; j++) {
            s += " ";
        }
        s += "*";
        cout << s << endl;
    }
}

void mid(int x) {
    string s = "";
    for (int i = 0; i < N - 1; i++) {
        s += " ";
    }
    s += "*";
    for (int i = 0; i < x; i++) {
        s += " ";
    }
    s += "*";
    for (int i = 0; i < x; i++) {
        s += " ";
    }
    s += "*";
    cout << s << endl;
}

void bot(int x) {
    string s = "";
    for (int i = 0; i < x; i++) {
        s = "";
        for (int j = 0; j < x - i; j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < x; j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < 1 + (i * 2); j++) {
            s += " ";
        }
        s += "*";
        for (int j = 0; j < x; j++) {
            s += " ";
        }
        s += "*";
        cout << s << endl;
    }
}

int main() {
    FastIO;

    cin >> N;

    string s = "";
    for (int i = 0; i < N; i++) {
        s += "*";
    }
    for (int i = 0; i < (N * 2) - 3; i++) {
        s += " ";
    }
    for (int i = 0; i < N; i++) {
        s += "*";
    }
    cout << s << endl;
    top(N - 2);
    mid(N - 2);
    bot(N - 2);
    cout << s << endl;

    return 0;
}