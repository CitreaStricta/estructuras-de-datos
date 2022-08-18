#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define ALPHABET_SIZE 26

using namespace std;

class TrieNode {
    private:
        TrieNode* character[ALPHABET_SIZE];
        int frequency;
        bool endOfWord;
    public:
        TrieNode();
        ~TrieNode();
        TrieNode* accessChild(char c);
        int getFrequency();
        bool isEndOfWord();
        void augmentFrequency();
        void insert(string s, int freq);
};