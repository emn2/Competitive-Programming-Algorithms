const int MAXN = 1e3 + 5;

bool visited[MAXN];
vector<pair<int, int> > ans;

class Graph{
    int V;
    list<int> *adj;
    
    public:
    Graph(int V)  { this->V = V;  adj = new list<int>[V];  }
    ~Graph()      { delete [] adj;  }

    void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
    void rmvEdge(int u, int v);

    void printEulerTour();
    void printEulerUtil(int s);

    int dfs(int v);

    bool isValidNextEdge(int u, int v);
};


void Graph::printEulerTour(){
    int u = 0;
    for(int i = 0; i < V; i++){
        if (adj[i].size() & 1){   
            u = i; 
            break;  
        }
    }

    printEulerUtil(u);
}


void Graph::printEulerUtil(int u){
    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        
        if (v != -1 && isValidNextEdge(u, v)){
            ans.push_back(make_pair(u, v));
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}


bool Graph::isValidNextEdge(int u, int v){
    int count = 0; 
    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i){
        if(*i != -1) count++;
    }

    if(count == 1) return true;

    memset(visited, false, V);
    int count1 = dfs(u);

    rmvEdge(u, v);
    memset(visited, false, V);
    int count2 = dfs(u);

    addEdge(u, v);

    return (count1 > count2)? false: true;
}


void Graph::rmvEdge(int u, int v){
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
    *iu = -1;
}

int Graph::dfs(int v){
    visited[v] = true;
    int count = 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += dfs(*i);

    return count;
}
