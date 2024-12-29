#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> um;

int solution(string s) {
    int answer = 0;
    
    um["zero"] = "0";
    um["0"] = "0";
    um["one"] = "1";
    um["1"] = "1";
    um["two"] = "2";
    um["2"] = "2";
    um["three"] = "3";
    um["3"] = "3";
    um["four"] = "4";
    um["4"] = "4";
    um["five"] = "5";
    um["5"] = "5";
    um["six"] = "6";
    um["6"] = "6";
    um["seven"] = "7";
    um["7"] = "7";
    um["eight"] = "8";
    um["8"] = "8";
    um["nine"] = "9";
    um["9"] = "9";
    
    string res = "";
    string temp = "";
    
    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        if (um.find(temp) != um.end()) {
            res += um[temp];
            temp = "";
        }
    }
    
    answer = stoi(res);    
    return answer;
}