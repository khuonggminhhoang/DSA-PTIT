#include<iostream>
#include<vector>

using namespace std;

int V,E, ok;
bool visited[1001];
vector <int> adj[1001];
int Parent[1001], size[1001];

void inp(){
    cin>>V>>E;
    while(E--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void Make_set(){
    for(int i=1; i<=V; ++i){
        Parent[i] = i;
        size[i] = 1;
    }
}

int find(int u){
    if(Parent[u] == u) return u;
    return  Parent[u] = find(Parent[u]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(size[u]<size[v]) swap(u,v);
        size[u] += size[v];
        Parent[v] = u;
    }
}

void DSU(int v){
    visited[v] = 1;
    for(auto x : adj[v]){
        if(!visited[x]){
            if(find(x) != find(v)){
                Union(v,x);
            }
            else {
                ok = 1;
                return;
            }
        }
    }
}

void setup(){
    for(int i=1; i<=V; ++i){
        adj[i].clear();
        visited[i] = 0;
        Parent[i] = 0;
        size[i] = 1;
    }
    ok = 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        inp();
        Make_set();
        for(int i=1; i<=V; ++i){
        	DSU(i);
		}
        cout<<(ok?"YES\n" : "NO\n");
        setup();
    }
    system("pause");
    return 0;
}

/*

3
6 9
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
4 3
1 2 2 3 3 4 
4 2
1 2 3 4

*/
