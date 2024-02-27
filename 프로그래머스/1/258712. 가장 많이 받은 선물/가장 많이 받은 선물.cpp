#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {

    vector<int> point(friends.size(), 0);
    vector<vector<int>> count(friends.size(), vector<int>(friends.size(), 0));
    map<string, int> m;

    for(int i=0;i< friends.size(); i++) 
        m.insert({friends[i], i});

    for(int i = 0; i < gifts.size(); i++) {
        string from, to;
        stringstream parse(gifts[i]);
        parse >> from >> to;

        int fromIdx = m[from], toIdx = m[to];
        count[fromIdx][toIdx]++;

        point[fromIdx]++;
        point[toIdx]--;
    }

    int ans = 0;

    for(int i = 0; i < friends.size(); i++) {
        int res = 0;

        for(int j = 0; j < friends.size(); j++) {
            if(i == j || count[i][j] < count[j][i]) continue;

            if(count[i][j] > count[j][i]) res++;
            else {
                if(point[i] > point[j]) res++;
            }
        }

        ans = max(res, ans);
    }

    return ans;
}