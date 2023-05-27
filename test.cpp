#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Edge {
    int dau, cuoi;  
};

class Graph{
    private:
        int n, a[100][100],start;
        bool chuaxet[100];
        vector <Edge> T;
    public : 
        void dataInput();
        void graphInit();
        void Tree_BFS(int start);
        int getStart(){
            return start;
        }
        void print();
};

void Graph::dataInput(){
    cin>>n>>start;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>a[i][j];
}

void Graph::graphInit(){
    for(int i=1; i<=n; ++i)
        chuaxet[i]=true;
}

void Graph::Tree_BFS(int start){
    queue <int> hangdoi;
    hangdoi.push(start);
    chuaxet[start]=false;
    while(!hangdoi.empty()){
        int u=hangdoi.front();
        hangdoi.pop();
        for(int v=1; v<=n; ++v){
            if( a[u][v] && chuaxet[v]){
                hangdoi.push(v);
                chuaxet[v]=false;
                if(u<v){
                    Edge e = {u,v};
                    T.push_back(e);
                }
                else {
                    Edge e = {v,u};
                    T.push_back(e);
                }
            }
        }
    }
}

void Graph::print(){
    if(T.size()<n-1) cout<<"No spanning tree";
    else{
        cout<<"Queue BFS tree\n";
        for(auto x : T){
            cout<<x.dau<<" "<<x.cuoi<<endl;
        }
    }
}

int main(){
    Graph g;
    g.dataInput();
    g.graphInit();
    g.Tree_BFS(g.getStart());
    g.print();
    return 0;
}
