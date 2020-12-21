#include "bits/stdc++.h"
using namespace std;

const int ALF = 26;

struct node {
    int wordCount, wordEnd;
    vector<int> next;
    node(int a = 0, int b = 0, vector<int> n = vector<int>(ALF, -1)): wordCount(a), wordEnd(b), next(n) {}
};

vector<node> trie(1);

int newNode(){
    trie.push_back(node());
    return trie.size() - 1;
}

void insert(string &s, int on = 0, int i = 0){
    trie[on].wordCount += 1;
    if(i == s.size()-1) trie[on].wordEnd += 1;

    if(s[i] == '\0') return;

    int to = s[i] - 'a';
    if(trie[on].next[to] == -1) trie[on].next[to] = newNode();

    insert(s, trie[on].next[to], i+1);
}

void deleteNode(string &s, int on = 0, int i = 0){
    int to = s[i] - 'a';
    if(trie[on].wordCount > 0) trie[on].wordCount -= 1;
    if(i == s.size() - 1){
        if(trie[on].wordEnd > 0) 
            trie[on].wordEnd -= 1;
        return;
    }
    else deleteNode(s, trie[on].next[to], i+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    return 0;
}
