void printCircuit(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back({v - 1, i});
        adj[v - 1].push_back({u - 1, i});
    }

    for(int i = 0 ; i < n; i++){
        if(adj[i].size() & 1){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
 
    stack<int> curr;
    vector<int> circuit;
    vector<bool> vis(m, false);
 
    curr.push(0);

    while(!curr.empty()){
        int u = curr.top();
        bool f = false;

        while(!adj[u].empty()){
            auto [v, i] = adj[u].back();
            adj[u].pop_back();
            if(!vis[i]){
                curr.push(v);
                vis[i] = true;
                f = true;
                break;
            }

        }
        if(!f){
            circuit.push_back(u + 1);
            curr.pop();
        }
    }

    if(circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(auto x : circuit)
        cout << x << ' ';
    cout << '\n';
}
