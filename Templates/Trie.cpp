#include <array>
#include <string>

struct Trie{
    bool suffix = false;
    int cnt = 0;
    std::array<Trie*, 26> next{};
};

Trie* root = new Trie();

void insert(std::string str) {
    Trie* pre = root;
    for(char c : str) {
        int pos = c - 'a';
        if(pre->next[pos] == nullptr) {
            pre->next[pos] = new Trie();
        }
        pre->next[pos]->cnt++;
        pre = pre->next[pos];
    }
    pre->suffix = true;
}

bool search(std::string str) {
    Trie* pre = root;
    for(char c : str) {
        int pos = c - 'a';
        if(pre->next[pos] == nullptr) {
            return false;
        }
        pre = pre->next[pos];
    }
    return pre->suffix;
}