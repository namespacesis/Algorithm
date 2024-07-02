#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// 자리수의 제곱합 계산 함수
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 두 수열의 길이 합의 최솟값을 계산
int sumEach(int a, int b) {
    vector<int> sequence1 = { a };
    vector<int> sequence2 = { b };

    if (a == b) {
        return 2;
    }

    while (true) {
        int sum1 = sumOfSquares(sequence1.back());
        if (find(sequence1.begin(), sequence1.end(), sum1) != sequence1.end()) {
            break;
        }
        else {
            sequence1.push_back(sum1);
        }
    }

    while (true) {
        int sum2 = sumOfSquares(sequence2.back());
        if (find(sequence2.begin(), sequence2.end(), sum2) != sequence2.end()) {
            break;
        }
        else {
            sequence2.push_back(sum2);
        }
    }

    unordered_set<int> set1(sequence1.begin(), sequence1.end());
    unordered_set<int> set2(sequence2.begin(), sequence2.end());

    vector<int> common;
    for (int num : set1) {
        if (set2.find(num) != set2.end()) {
            common.push_back(num);
        }
    }

    if (!common.empty()) {
        int minLength = INT_MAX;
        for (int commonNum : common) {
            int len1 = find(sequence1.begin(), sequence1.end(), commonNum) - sequence1.begin();
            int len2 = find(sequence2.begin(), sequence2.end(), commonNum) - sequence2.begin();
            minLength = min(minLength, len1 + len2 + 2);
        }
        return minLength;
    }
    else {
        return 0;
    }
}

int main() {
    FastIO;

    vector<pair<int, int>> cases;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        cases.push_back({ a, b });
    }

    for (const auto& c : cases) {
        int result = sumEach(c.first, c.second);
        cout << c.first << " " << c.second << " " << result << "\n";
    }

    return 0;
}
