#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N;
string words[30];
unordered_map<char, bool> um;

int main() {
    FastIO;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, words[i]);
    }

    vector<string> res;

    for (int i = 0; i < N; i++) {
        vector<string> v;
        stringstream ss(words[i]);
        string temp;

        while (ss >> temp) {
            v.push_back(temp);
        }

        bool check = false;

        for (int j = 0; j < v.size(); j++) {
            if (um.find(toupper(v[j][0])) == um.end()) {
                um[toupper(v[j][0])] = true;
                v[j].insert(1, "]");
                v[j].insert(0, "[");
                check = true;
                break;
            }
        }

        if (!check) {
            for (int j = 0; j < v.size(); j++) {
                for (int k = 1; k < v[j].size(); k++) {
                    if (um.find(toupper(v[j][k])) == um.end()) {
                        um[toupper(v[j][k])] = true;
                        v[j].insert(k + 1, "]");
                        v[j].insert(k, "[");
                        check = true;
                        break;
                    }
                }
                if (check) break;
            }
        }

        string ans;
        for (int j = 0; j < v.size(); j++) {
            if (j > 0) ans += " ";
            ans += v[j];
        }
        res.push_back(ans);
    }

    for (string s : res) {
        cout << s << "\n";
    }

    return 0;
}
