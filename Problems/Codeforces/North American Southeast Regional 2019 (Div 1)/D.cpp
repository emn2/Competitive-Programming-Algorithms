#include<bits/stdc++.h>
using namespace std;
const int inf = 1e5;
struct Edge{
	int u,v;
	int cap,flow;
	Edge(int _u,int _v, int cap):u(_u),v(_v),cap(cap),flow(0){}
};

struct Dinic{
	const int flow_inf = 1e6;
    int m = 0, n;
	vector<Edge>edges;
	vector<vector<int>>adj;
	vector<int>dist,ptr;

	Dinic(int _n):n(_n),adj(n),dist(n),ptr(n){}

	void addEdge(int u, int v, int cap){
		if(u!=v) {
			edges.emplace_back(u,v,cap);
			edges.emplace_back(v,u,0);
            adj[u].emplace_back(m++);
			adj[v].emplace_back(m++);
		}		
	}
	bool bfs(int s, int t){
		fill(begin(dist),end(dist),n+1);

		dist[s]=0;
		queue<int>q({s});

		while(!q.empty()){
			int u = q.front();
            q.pop();
			if(u==t)break;

			for(int id:adj[u]){
				Edge &e = edges[id];
				if(e.flow<e.cap && dist[e.v]>dist[e.u]+1){
					dist[e.v]=dist[e.u]+1;
					q.emplace(e.v);
				}
			}
		}

		return dist[t]!=n+1;
	}

	int dfs(int u, int t,int flow){
		if(u==t||flow==0){
			return flow;
		}

		for(int &i=ptr[u];i<(int)adj[u].size();i++){
			Edge &e=edges[adj[u][i]];
			Edge &oe=edges[adj[u][i]^1];

			if(dist[e.v]==dist[e.u]+1){
				int amt=e.cap-e.flow;
				amt=min(flow,amt);

				if(int ret=dfs(e.v,t,amt)){
					e.flow+=ret;
					oe.flow-=ret;
					return ret;
				}
			}
		}
		return 0;
	}

	int maxFlow(int s, int t){
		int total=0;
		while(bfs(s,t)){
			fill(begin(ptr),end(ptr),0);
			while(int flow=dfs(s,t,flow_inf)){
				total+=flow;
			}
		}

		return total;
	}
	//returns where in the min-cut (S,T) the vertex u is
	//false: u in S, true: u in T
	bool cut(int u){return dist[u]==n+1;}
};

bool bad(const string& s, const string& t){
	int n = (int)s.size();
	int dif = 0;
	for(int i=0;i<n;++i){
		dif += (s[i] != t[i]);
	}
	return dif == 2;
}
const int ms = 500 + 20;
int color[ms];
bool isBad[ms][ms];
vector<int>adj[ms];
bool bfscolor(int st){
	bool bipartite = true;
	queue<int>q({st});
	color[st] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : adj[u]){
			if(color[v] == -1){
				color[v] = color[u] ^ 1;
				q.push(v);
			}else{
				bipartite &= color[u] != color[v];
			}
		}
	}
	return bipartite;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
	vector<string>v(n+1);
	for(int i=1;i<=n;++i)cin>>v[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			isBad[i][j] = bad(v[i],v[j]); 
			if(isBad[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	memset(color,-1,sizeof(color));
	for(int i=1;i<=n;++i){
		if(color[i] == -1){
			bfscolor(i);
		}
	}
	Dinic kinho(n + 2);
	int source = 0;
	int sink = n + 1;
	for(int i=1;i<=n;++i){
		if(color[i])kinho.addEdge(i,sink,1);
		else kinho.addEdge(source,i,1);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(isBad[i][j]){
				if(color[i])kinho.addEdge(j,i,1);
				else kinho.addEdge(i,j,1);
			}
		}
	}

	cout<<n - kinho.maxFlow(source,sink)<<'\n';
	
    return 0;
}
