#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 510;
string grid[maxn];

int R, C;
string base = "URDL";
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int r, c;
	
int dir_at, dir_sim;

bool check_next(int d){
	int new_r = r + dr[d];
	int new_c = c + dc[d];
	return grid[new_r][new_c] == '.';
}

void simul(int steps){
	if(steps == 0)
		return;
	
	while(!check_next(dir_sim)){
		dir_sim++;
		if(dir_sim >= 4)
			dir_sim -= 4;
	}
	
	r += dr[dir_sim];
	c += dc[dir_sim];
	
	simul(steps-1);
}

int fix_rot(){
	
	while(!check_next(dir_sim)){
		dir_sim++;
		if(dir_sim >= 4)
			dir_sim -= 4;
	}
	
	int temp_sim = dir_sim;
	int ans = 0;
	while(temp_sim != dir_at){
		temp_sim--;
		if(temp_sim < 0)
			temp_sim += 4;
		if(check_next(temp_sim) || ans != 0)
			ans++;
	}
	
	return ans;
}

void solve(){
	
	int q;
	cin >> R >> C >> q;
	char in;
	cin >> r >> c >> in;
	r--, c--;
	
	for(int i = 0; i < R; i++)
		cin >> grid[i];
	
	int dir = -1;
	for(int i = 0; i < 4; i++)
		if(in == base[i])
			dir = i;
	
	//cout << 'q' << endl;
	dir_at = dir_sim = dir;
	
	char op;
	int steps;
	int ans = 0;
	int rots;
	while(q--){
		//cout << q << endl;
		cin >> op;
		if(op == 'F'){
			cin >> steps;
			rots = fix_rot();
			if(ans == 0 || rots > 0)
				ans++;
			ans += rots;
			simul(steps);
			dir_at = dir_sim;
		}
		else{
			dir_sim++;
			if(dir_sim >= 4)
				dir_sim -= 4;
		}
	}
	
	cout << ans << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("reduce.in", "r", stdin);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
