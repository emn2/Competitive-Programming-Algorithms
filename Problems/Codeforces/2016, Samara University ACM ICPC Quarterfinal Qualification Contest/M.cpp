#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
vector<int> perd[maxn];

bool ask(int x, int y){
    cout<<"? "<<x<<' '<<y<<endl;
    char c;cin>>c;
    return c == '<';
}

int main(){
	int n;cin>>n;
	queue<int>q;
	
	for(int i=1;i<=n;++i)q.push(i);
	while(q.size() > 1){
		int u = q.front();
		q.pop();
		int v = 0;
		if(!q.empty()){v = q.front();q.pop();}
		
		if(v != 0){
			bool r = ask(u,v);
			if(r){
				q.push(v);
				perd[v].push_back(u);
			}
			else{
				q.push(u);
				perd[u].push_back(v);
			}
		}
	}
	
	int ganhador = q.front();
	q.pop();
	
	for(int i = 0; i < perd[ganhador].size(); i++)
		q.push(perd[ganhador][i]);
	
	while(q.size() > 1){
		int u = q.front();
		q.pop();
		int v = 0;
		if(!q.empty()){v = q.front();q.pop();}
		
		if(v != 0){
			bool r = ask(u,v);
			if(r){
				q.push(v);
				perd[v].push_back(u);
			}
			else{
				q.push(u);
				perd[u].push_back(v);
			}
		}
	}
	
	cout << "! " << q.front() << endl;
	
	return 0;
}
