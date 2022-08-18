#include "TrieNode.h"

class Predictor {
private:
    TrieNode* trie;
    void searching(queue<pair<string, int>>* p, TrieNode* curNode, string root);
public:
    Predictor();
    ~Predictor();
    void insert(string s, int freq);
    bool wordIsInTrie(string s);
    TrieNode* searchWord(string s);
    queue<pair<string, int>>* search(string root);
    void search(string root, queue<pair<string, int>>* resp, char ignore);
    queue<pair<string, int>>* predict(string root, int k_mostFrequent);    
    void augmentFrequency(string s);
};
