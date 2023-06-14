#include<iostream>

using namespace std;

class Graph{
    private :
        int n, start, a[100][100], x[100];
        bool chuaxet[100];
    public:
        void dataInput();
        void Hmt(int k);
        void graphInit();
        void Hamilton_Cyrcle(int start);
        void print();
        int getStart();
};

int Graph::getStart(){
    return start;
}

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

void Graph::print(){
    for(int i=1; i<=n+1; ++i){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void Graph::Hmt(int k){
    for(int v=1; v<=n; ++v){
        if(a[x[k-1]][v]){
            if(k==n+1 && v==start) {
                x[k]=v;
                print();
            }
            else{
                if(chuaxet[v]){
                   x[k]=v;
                   chuaxet[v]=false;
                   Hmt(k+1);
                   chuaxet[v]=true;
                }
                
            }
        }
    }
}

void Graph::Hamilton_Cyrcle(int start){
    graphInit();
    x[1]=start;
    chuaxet[start]=false;
    Hmt(2);
}

int main(){
    Graph g;
    g.dataInput();
    g.graphInit();
    g.Hamilton_Cyrcle(g.getStart());
    system("pause");
}

/*
4
3
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/

