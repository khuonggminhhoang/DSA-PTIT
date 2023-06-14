#include<iostream>
#include<vector>

using namespace std;

int V,E, ok ,a[1001] = {-1};
bool visited[1001];
vector <int> adj[1001];

void inp(){
    cin>>V>>E;
    while (E--)
    {
        int  x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=V; ++i) a[i] = -1;
    ok = 1;
}

void DFS(int v){
    visited[v] = 1;
    for(auto x : adj[v]){
        if(!visited[x]){
            if(a[v]==0){
                if(a[x]==-1){
                    a[x] = 1;
                }
                else if(a[x] == 0){
                    ok = 0;
                    return;
                }
            }
            else if(a[v] == 1){
                if(a[x] == -1) a[x] = 0;
                else if(a[x] == 1) {
                    ok = 0;
                    return;
                }
            }
        }
    }
    for(auto x : adj[v]){
    	if(!visited[x]) DFS(x);
	}
}

void setup(){
    for(int i=1; i<=V; ++i){
        adj[i].clear();
        visited[i] = 0;
        a[i] = -1;
        ok = 1;
    }
}

void ReInit(){
    for(int i=1; i<=V; ++i){
        visited[i] = 0;
        a[i] = -1;
    }
}

main(){
    int t;
    cin>>t;
    while (t--)
    {
        inp();
        for(int u = 1; u<=V; ++u){
            a[u] = 0;
            DFS(u);
            if(!ok) break;
            ReInit();
        }

        cout<<(ok?"YES\n" : "NO\n");
        setup();
    }
    system("pause");
}
