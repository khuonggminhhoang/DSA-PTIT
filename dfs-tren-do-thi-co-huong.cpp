#include<iostream>
#include<vector>

using namespace std;

bool chuaxet[1001];
void DFS(int start, vector <int> ke[]){
	cout<<start<<" ";
	chuaxet[start]=false;
	for(auto x : ke[start]){
		if(chuaxet[x]){
			DFS(x,ke);
		}
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int vertex,edge,start;
		cin>>vertex>>edge>>start;
		vector <int> ke[vertex+1];
		while(edge--){
			int x, y;
			cin>>x>>y;
			ke[x].push_back(y);
		}
		
		for(int i=1; i<=vertex; ++i) 
			chuaxet[i]=true;
		DFS(start,ke);
		cout<<endl;
	}
}
