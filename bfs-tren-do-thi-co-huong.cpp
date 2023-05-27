#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph{
	private:
		int vertex, edge, start;
		vector <int> ke[1001];
		bool chuaxet[1001];
	public:
		void dataInput();
		void graphInit();
		void BFS(int start);	
		int getStart(){
			return start;
		}
};

void Graph::dataInput(){
	cin>>vertex>>edge>>start;
	while(edge--){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
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
		int s = hangdoi.front();
		hangdoi.pop();
		for( auto x : ke[s]){
			if(chuaxet[x]){
			cout<<x<<" ";
			chuaxet[x]=false;
			hangdoi.push(x);
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
		g.graphInit();
		g.BFS(g.getStart());
		cout<<endl;
	}
}
