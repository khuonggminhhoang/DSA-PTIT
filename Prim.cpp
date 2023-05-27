#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge{
    int u,v,w; 
};

class Graph{
    private:
        int n, start, a[100][100], dH;
        vector <Edge> vctEdge, T;
        vector <int> vct;
        bool V[100];
    public:
        void dataInput();
        void transEdgeList();
        void graphInit();
        void Prim(int start);
        void print();
        int getStart(){
            return start;
        }
};

void Graph::graphInit(){
    for(int i=1; i<=n; ++i) V[i]=true;
}

void Graph::dataInput(){
    cin>>n>>start;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>a[i][j];
}

bool cmp(Edge a, Edge b){
    if(a.w != b.w) return a.w<b.w;
    else if(a.u != b.u) return a.u<b.u;
        else return a.v<b.v;
}

void Graph::transEdgeList(){
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(a[i][j] != 0){
                Edge e = {i,j,a[i][j]};
                vctEdge.push_back(e);
            }
        }
    }
    sort(vctEdge.begin(), vctEdge.end(), cmp);
    for(auto x : vctEdge) cout<<"("<<x.u<<","<<x.v<<");";
}

void Graph::print(){
    cout<<"dH="<<dH<<endl;
    for(auto x:T){
        cout<<x.u<<" "<<x.v<<endl;
    }
//    for(auto x : vctEdge){
//    	cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
//	}
}

void Graph::Prim(int s){
    V[s]=false;
    dH=0;
    vct.push_back(s);
    while(vct.size() != n){
        for(auto x : vctEdge){
            if( V[x.u]==false && V[x.v]==true ){
                T.push_back(x);
                V[x.v]=false;
                vct.push_back(x.v);
                dH+=x.w;
                break;
            }
            if(V[x.v]==false && V[x.u]==true){
            	T.push_back(x);
                V[x.u]=false;
                vct.push_back(x.u);
                dH+=x.w;
                break;
			}
        }
    }
    
}

int main(){
    Graph g;
    g.dataInput();
    g.transEdgeList();
    g.graphInit();
    g.Prim(g.getStart());
    g.print();
    
    return 0;
}
