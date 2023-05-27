#include<iostream>
#include<queue>

using namespace std;

class Graph{
	private:
		int vertex, edge, start;
		vector <int> adj[1005];
		bool chuaxet[1005];
	public:
		void dataInput();
		void graphInit();
		void dsKe();
		int getStart();
		void BFS(int u);
};

int Graph::getStart(){
	return start;
}

void Graph::dataInput(){
	cin>>vertex>>edge>>start;
}

void Graph::dsKe(){
	for(int i=0; i<edge; ++i){
			int x, y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
}

void Graph::graphInit(){
	for(int i=1; i<=vertex; ++i)
		chuaxet[i]=true;
}

void Graph::BFS(int u){
	queue <int> hangdoi;
	cout<<u<<" ";
	chuaxet[u]=false;
	hangdoi.push(u);
	while(!hangdoi.empty()){
		int s=hangdoi.front();
		hangdoi.pop();
		for(auto v:adj[s]){
			if(chuaxet[v]){
				cout<<v<<" ";
				chuaxet[v]=false;
				hangdoi.push(v);
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
		g.dsKe();
		g.graphInit();
		g.BFS(g.getStart());
		cout<<endl;
	}
}
