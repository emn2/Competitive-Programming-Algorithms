const int ms = 1e5 + 100;

struct Trie{
    int trie[ms][ALF], terminal[ms], z;

    void Trie(){
        memset(trie[0], -1, sizeof(trie[0]));
        z = 1;
    }

    void insert(string &p){
        int cur = 0;
        for(int i = 0; i < p.size(); i++){
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
        for(int i = 0; i < p.size(); i++){
            int id = p[i] - 'a';
            if(trie[cur][id] == -1) return false;
            cur = trie[cur][id];
        }
        return terminal[cur];
    }

    //print words with a given prefix
    void print(int cur, string ans){
        if(terminal[cur]){
            cout << ans << '\n';
        }
        for(int i = 0; i < ALF; i++){
            if(trie[cur][i] != -1){
                ans.push_back(i + 'a');
                print(trie[cur][i], ans);
                ans.pop_back();
            }
        }
    }
};
