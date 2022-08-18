#include "TrieNode.h"

TrieNode::TrieNode()
{
    this->endOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        character[i] = nullptr;
    this->frequency = 0;
}

TrieNode::~TrieNode()
{
    for (int i = 0; i < 26; i++)
        delete this->character[i];
}

TrieNode* TrieNode::accessChild(char c)
{
    return character[c - 97];
}

void TrieNode::insert(string s, int freq)
{
    TrieNode* curNode = this; // Guarda la direccion de memoria de la "raiz"
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 97; // transforma la letra "s[i]" en su numero ascii
        if (curNode->character[index] == nullptr) // "si 'character' no tiene la letra 'index'
            curNode->character[index] = new TrieNode(); // entonces creo un nodo apuntado por 'character[index]'"
        curNode = curNode->character[index]; // Entra al nodo "character[index]" y continua con el ciclo "for"
    }
    curNode->endOfWord = true; // cuando el string termine, el nodo actual se marca como end of word
    curNode->frequency = freq;
}

int TrieNode::getFrequency()
{
    if (this->isEndOfWord())
        return this->frequency;
    else
        return -1;
}

void TrieNode::augmentFrequency()
{
    if (this->isEndOfWord())
        this->frequency++;
}

bool TrieNode::isEndOfWord() {
    return this->endOfWord;
}
