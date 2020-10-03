#include "bits/stdc++.h"
using namespace std;

int main(){
    int u, v, n, start; //n -> number of nodes
    cin >> n >> start;
    queue<int> q;
    queue<int> ans; //queue to print the answer
    vector<vector<int> > adjList (n);
    vector<bool> visited (n, false); 

    while(cin >> u >> v){
        adjList[u].push_back(v);
    }
    
    q.push(start); //starting point
    ans.push(start);
    visited[0] = true;

    while(!q.empty()){
        int current = q.front(); //the current node is the first in the queue
        q.pop();

        for(int to: adjList[current]){ //passing through all nodes connected to the current
            if(visited[to] == false){ //if was not already visited, mark as visited
                visited[to] = true;
                q.push(to); //put in the end of the queue
                ans.push(to); //put in the answer queue
            }
        }   
    }

    while(!ans.empty()){ //print the answer
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}
