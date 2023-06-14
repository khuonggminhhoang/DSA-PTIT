#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V,E, vert;
bool visited[1001];
vector <int> adj[1001];
int truoc[1001];

void inp(){
    cin>>V>>E;
    while(E--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=V;++i) sort(adj[i].begin(), adj[i].end());
}

bool DFS(int u, int par){
    visited[u] = 1;
    for(auto x : adj[u]){
        if(!visited[x]){
            if(DFS(x,u)) {
                truoc[x] = u;
                return true;
            }
        }
        else{
            if(x != par && x == 1) {
               	vert = u; 
               	return true;
            }
        }
    }
    return false;
}

void Trace(int vert){
    vector <int> CE;
    CE.push_back(1);
    CE.push_back(vert);
    int x = truoc[vert];
    while(x != 1){
        CE.push_back(x);
        x = truoc[x];
    }
    CE.push_back(x);
    reverse(CE.begin(), CE.end());
    for(auto x : CE) cout<<x<<" ";
    cout<<endl;
}

void setup(){
    for(int i=1; i<=V; ++i){
        adj[i].clear();
        visited[i] = 0;
        truoc[i] = 0;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        inp();
        if(DFS(1,0)) Trace(vert);
        else cout<<"NO\n";
        setup();
    }
    system("pause");
    return 0;
}

/*

5
7 8
1 2 1 3 2 3 2 4 4 5 5 6 6 7 7 3
6 9
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
5 5
1 2 2 3 3 4 4 5 5 2
4 3
2 3 2 4 3 4
5 6 
1 2 3 5 2 3 2 5 3 4 4 5
*/
