#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
    int s, e, w;
};

class Graph{
    private:
        int n, a[100][100];// sz[100];
        vector <Edge> ds;
        int parent[100];
    public:
        void dataInput();
        int find(int v);
        bool Union(int u, int v);
        void Make_set();
        void Kruskal();
};

void Graph :: Make_set(){
    for( int i=1; i<=n; ++i){
        parent[i]=i;
       // sz[i]=1;
	}
}

int Graph :: find(int v){
    if( v == parent[v]) return v;
    return parent[v]= find(parent[v]);
}

bool Graph :: Union(int a, int b){
    a = find(a);
	b = find(b);
	if(a == b) return false; // khong the gop a, b vao voi nhau
//	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
//	sz[a] + sz[b];
	return true;
}

bool cmp( Edge a, Edge b){
    if(a.w != b.w) return a.w < b.w;
    else if(a.s != b.s) return a.s<b.s;
    else return a.e < b.e;
}

void Graph::dataInput(){
    cin>>n;
    for(int i=1; i<=n; ++i) 
        for(int  j=1; j<=n; ++j)
            cin>>a[i][j];
            
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            if(a[i][j] != 0 ){
                Edge canh = {i,j,a[i][j]};
                ds.push_back(canh);
            }
        }
    }
}

void Graph :: Kruskal(){
    int dH=0;
    int T=0;      
    vector <Edge> v;
    sort(ds.begin(), ds.end(), cmp);
    while( T < n-1 && !ds.empty()){
        Edge edge = ds[0];
        ds.erase(ds.begin());  	
        if(Union(edge.s, edge.e)){
            ++T;
            dH += edge.w;
            v.push_back(edge);
        }
    }
    
    cout<<"dH = "<<dH<<endl;
    for( auto x : v){
        cout<<x.s<<" "<<x.e<<endl;
    }
}


int main(){
    Graph g;
    g.dataInput();
    g.Make_set();
    g.Kruskal();
    return 0;
}
