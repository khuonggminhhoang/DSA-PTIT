#include<iostream>
#include<vector>

using namespace std;

int V,E,ok;
bool visited[100001];
vector <int> adj[100001];

void inp(){
    cin>>V>>E;
    while(E--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ok=1;
}

void DFS(int v){
    visited[v] = 1;
    for(auto x : adj[v]){
        if(!visited[x]){
            visited[x] = 1;
            if(adj[x].size() != adj[v].size()){
                ok = 0;
                return;
            }
        }
    }
}

void solve(){
    for(int u=1; u<=V; ++u){
        if(!visited[u]) DFS(u);
    }
    cout<<(ok? "YES\n" : "NO\n");
}

void setup(){
    for(int i=1; i<=V; ++i){
        adj[i].clear();
        visited[i] = 0;
        ok = 1;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
		inp();
        // solve();
        setup();
    }
    system("pause");
    return 0;
}