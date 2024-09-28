#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    int countKeyPresses(const string& word) {
        TrieNode* current = root;
        int keyPresses = 0;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (i == 0) {
                keyPresses++;
            }
            else {
                if (current->children.size() > 1 || current->isEndOfWord) {
                    keyPresses++;
                }
            }

            current = current->children[c];
        }
        return keyPresses;
    }
};

int main() {
    FastIO;

    int n;

    while (cin >> n) {
        vector<string> words(n);
        Trie trie;

        for (int i = 0; i < n; i++) {
            cin >> words[i];
            trie.insert(words[i]);
        }

        double totalKeyPresses = 0;
        for (const string& word : words) {
            totalKeyPresses += trie.countKeyPresses(word);
        }

        cout << fixed;
        cout.precision(2);
        cout << totalKeyPresses / n << "\n";
    }

    return 0;
}
