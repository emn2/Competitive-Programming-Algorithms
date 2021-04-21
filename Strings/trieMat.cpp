#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int ms = 500010;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)

int trie[ms][26], terminal[ms], z;

void init(){
    memset(trie[0], -1, sizeof(trie[0]));
    z = 1;
}

void insert(string &p){
    int cur = 0;
    forc(i, 0, p.size()){
        int id = p[i] - 'a';
        if(trie[cur][id] == -1){
            memset(trie[z], -1, sizeof(trie[z]));
            trie[cur][id] = z++;
        }
        cur = trie[cur][id];
    }
    terminal[cur]++;
}

int count(string &p){
    int cur = 0;
    forc(i, 0, p.size()){
        int id = p[i] - 'a';
        if(trie[cur][id] == -1) return false;
        cur = trie[cur][id];
    }
    return terminal[cur];
}
