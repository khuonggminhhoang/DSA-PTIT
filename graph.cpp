#include<iostream>
#include<list>
#include<fstream>

using namespace std;

class Graph{
		int V;
		list <int> *adj;
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void printGraph();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list <int> [V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::printGraph(){
	int v;
	for(int v=1; v<V; ++v){
		cout<<"\n danh sach ke cua dinh "<< v <<"\n head";
		for( list <int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i){
			cout<<"->"<<*i;
		}
		cout<<endl;
	}
}

main(){
//	ifstream fp("dothiin.txt");
	int n,m, dau, cuoi;
	cin>>n>>m;
	Graph gh(n+1);
	for(int i=1; i<=m; ++i){
		cin>>dau>>cuoi;
		gh.addEdge(dau,cuoi);
	}
//	fp.close();
	gh.printGraph();
}
