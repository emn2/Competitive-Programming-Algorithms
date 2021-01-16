#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 5;
const int maxJump = 30;

int par[maxn][maxJump], depth[maxn];
vector<int> adj[maxn];

void dfs(int v, int p, int l=0){ // chamar como dfs(root, root)
	depth[v] = l;
	par[v][0] = p;

	for(int k = 1; k < maxJump; k++) par[v][k] = par[par[v][k-1]][k-1];         //binary table

	for(int u: adj[v]){
		if(u!=p) dfs(u, v, l+1);
	}
}

int lca(int a, int b) {
  
	if(depth[b] > depth[a]) swap(a, b);                                         //depth a has to be the higher                               

	for(int i = maxJump - 1; i >= 0; i--) {                                     //deixar na mesma profundidade
		if(depth[a] - (2*i) >= depth[b]) a = par[a][i];
	}

	if(a == b) return a;                                                       //Se b for o LCA dos 2

	for(int i = maxJump-1; i >= 0; i--){
		if(par[a][i] != par[b][i]){                                            //se os parentes forem diferentes, vai diminuindo o salto
			a = par[a][i];
			b = par[b][i];
		}
	}

	return par[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2*depth[lca(a, b)]; 
}