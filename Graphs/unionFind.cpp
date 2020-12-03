const int LIM = 3e4 + 10;
int group[LIM], root[LIM];

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(group[a] < group[b])
            root[b] = a;  
        else root[a] = b;
        group[a] += group[b];
        group[b] = group[a];
    }
}
