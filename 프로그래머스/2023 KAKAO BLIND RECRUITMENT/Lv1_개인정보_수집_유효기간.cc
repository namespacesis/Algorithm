#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int ty, tm, td;
    replace(today.begin(), today.end(), '.', ' ');
    stringstream ss(today);
    ss >> ty >> tm >> td;

    map<char, int> termMap;
    for (const string& term : terms) {
        istringstream ss(term);
        char alpha;
        int num;
        ss >> alpha >> num;
        termMap[alpha] = num;
    }

    for (int i = 0; i < privacies.size(); i++) {
        string privacie = privacies[i];
        int y, m, d;
        char alpha;
        replace(privacie.begin(), privacie.end(), '.', ' ');
        istringstream ss(privacie);
        ss >> y >> m >> d >> alpha;

        m += termMap[alpha];

        while (m > 12) {
            y++;
            m -= 12;
        }

        d--;
        if (d == 0) {
            d = 28;
            m--;
            if (m == 0) {
                y--;
                m = 12;
            }
        }

        if (ty > y || (ty == y && tm > m) || (ty == y && tm == m && td > d)) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}