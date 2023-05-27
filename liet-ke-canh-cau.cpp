#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Graph{
	private:
		int vertex, edge;
		vector <int> a[1005];
		bool chuaxet[1005];
	public:
		void dataInput();
		void graphInit();
		int DFS(int u);
		void Duyet_Cau();
};

void Graph::dataInput(){
	cin>>vertex>>edge;
	for(int i=1; i<=vertex; ++i)
		for(int j=0; j<=vertex; ++j)
			a[i].push_back(0);
	for(int i=0; i<edge; ++i){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
}

void Graph::graphInit(){
	for(int i=1; i<=vertex; ++i)
		chuaxet[i]=true;
}

int Graph::DFS(int u){
	stack <int> stk;
	int cnt=1;
	stk.push(u);
	chuaxet[u]=false;
	while(!stk.empty()){
		int s=stk.top();
		stk.pop();
		for(int v=1; v<=vertex; ++v){
			if(a[s][v]==1 && chuaxet[v]){
				++cnt;
				chuaxet[v]=false;
				stk.push(s);
				stk.push(v);
				break;
			}
		}
	}
	return cnt;
}

void Graph::Duyet_Cau(){
	for(int u=1; u<=vertex; ++u){
		for(int v=u; v<=vertex; ++v){
			if(a[u][v]){
				graphInit();
				a[u][v]=0;
				a[v][u]=0;
				if(DFS(1)!=vertex){
					cout<<u<<" "<<v<<" ";
				}
				a[u][v]=1;
				a[v][u]=1;
			}
		}
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		Graph g;
		g.dataInput();
		g.Duyet_Cau();
		cout<<endl;
	}
}

