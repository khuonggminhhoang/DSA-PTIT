#include<iostream>

using namespace std;

const int INF = 1e9;

class Graph{
    private: 
        int n, start;
        int truoc[100], a[100][100], d[100];
        bool tick[100];
    public:
        void dataInput();
        void Dijkstra(int start);
        void graphInit();
        int getStart(){
            return start;
        }
        void print(int start);
};

void Graph::print(int u){
    for(int v = 1; v<=n; ++v){
    	if(d[v] != INF){
	        cout<<"K/c "<<u<<" -> "<<v<<" = "<< d[v] <<";   ";
	        cout<<v<<" <- ";
	        int s = truoc[v];
	        while(s != u){
	            cout<<s<< " <- ";
	            s= truoc[s];
	        }
	        cout<<s<<endl;
		}
		else cout<<"K/c "<<u<<" -> "<<v<<" = INF;"<<endl;
    }
}

void Graph::dataInput(){
    cin>>n>>start;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin>>a[i][j];
            if(a[i][j]==0) a[i][j] = INF;
        }
    }
}

void Graph::graphInit(){
    for(int i=1; i<=n; ++i){
        tick[i]= false;
    }
}

void Graph::Dijkstra(int start){
    for(int i=1; i<=n; ++i){
        if(i==start) {
            d[i]=0;
            truoc[i] = start;
        }
        else{
            if(a[start][i]!=0) {
                 d[i]= a[start][i];
                 truoc[i] = start;
            }
            else d[i] = INF;
        }
    }

    tick[start] = true;
    int T = n-1;
    while(T--){
        int u=0, min_=1e9;
        for(int i=1; i<=n; ++i){
            if(!tick[i]){
                if(d[i] < min_){
                    min_ = d[i];
                    u = i;
                }
            }
        }
        if(u!=0){
	        tick[u] = true;
	        for(int v = 1; v <= n; ++v){
	            if(!tick[v]){
	                if(d[v] > d[u] + a[u][v]){
	                    d[v] = d[u] + a[u][v];
	                    truoc[v] = u;
	                }
	            }
	        }
		}
		else break;
    }
}



int main(){
    Graph g;
    g.dataInput();
    g.Dijkstra(g.getStart());
    g.print(g.getStart());
    
    return 0;
}
