#include<iostream>
#include<queue>
#define MAX 100

using namespace std;

class Graph {
	private:
		int n, A[MAX][MAX];
		bool chuaxet[MAX];
		
	public:
		void dataInput();
		void graphInit();
		void vertexVisit(int v);
		void queueBFS(int u);
		void recursiveDFS(int u);
		int duyet_STPLT();
};

void Graph :: dataInput(){
	cin>>n;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)	
			cin>>A[i][j];
}

void Graph :: graphInit(){
	for(int i=1; i<=n; ++i) 
		chuaxet[i]=true;
}

void Graph :: vertexVisit(int v){
	cout<<v<<" ";
	chuaxet[v]=false;
}

void Graph::recursiveDFS(int u){
	  vertexVisit(u);
	  for(int v=1; v<=n; ++v){
	  	if( A[u][v]==1 && chuaxet[v])
	  		recursiveDFS(v);
	  }
}

int Graph::duyet_STPLT(){
	int soTPLT=0;
	for(int u=1; u<=n; ++u){
		if(chuaxet[u]){
			soTPLT+=1;
			recursiveDFS(u);
		}
	}
	return soTPLT;
}

void Graph :: queueBFS(int u){
	queue <int> hangdoi;
	hangdoi.push(u);
	vertexVisit(u);
	while(!hangdoi.empty()){
		int s = hangdoi.front();
		hangdoi.pop();
		for( int v = 1; v<=n; ++v){
			if(A[s][v] && chuaxet[v]){
				vertexVisit(v);
				hangdoi.push(v);
			}
		}
	}
}

main(){
	Graph g;
	g.dataInput();
	g.graphInit();
	g.queueBFS(8);
//	g.recursiveDFS(1);
//	cout<<g.duyet_STPLT();
}
