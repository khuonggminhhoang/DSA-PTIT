#include<iostream>
#include<vector>

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
		void DFS(int start);
		int getStart();
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

void Graph::DFS(int start){
	cout<<start<<" ";
	chuaxet[start]=false;
	for(auto x : adj[start]){
		if(chuaxet[x]){
			chuaxet[x]=false;
			DFS(x);
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
		g.DFS(g.getStart());
		cout<<endl;
	}
}
