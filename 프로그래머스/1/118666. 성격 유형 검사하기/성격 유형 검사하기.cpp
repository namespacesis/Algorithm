#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> um;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < choices.size(); i++) {
        int c = choices[i];
        if (c <= 3) {
            char ch = survey[i][0];
            int score = (3 / c) + (3 % c);
            um[ch] += score;
        }
        else if (c >= 5) {
            char ch = survey[i][1];
            int score = c - 4;
            um[ch] += score;
        }
    }
    
    if (um['R'] >= um['T']) answer += "R";
    else answer += "T";
    if (um['C'] >= um['F']) answer += "C";
    else answer += "F";
    if (um['J'] >= um['M']) answer += "J";
    else answer += "M";
    if (um['A'] >= um['N']) answer += "A";
    else answer += "N";
    
    return answer;
}