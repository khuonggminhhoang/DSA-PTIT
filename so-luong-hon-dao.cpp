#include<iostream>

using namespace std;

int n,m;
const int dx[] = {-1, -1, -1 , 0, 0, 1, 1, 1};
const int dy[] = {-1, 0 , 1, -1, 1, -1, 0, 1};
int a[501][501];

void DFS(int x, int y){
	a[x][y] =  0;
	for(int i=0; i<8; ++i){
		int X = x + dx[i];
		int Y = y + dy[i];
		if( X >=1 && X <=n && Y >=1 && Y <= m && a[X][Y] == 1){
			DFS(X,Y);
		}
	}
}

int counter(){
	int cnt=0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 1) {
				cnt++;
				DFS(i,j);
			}
		}
	}
	return cnt;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j) 
			cin>>a[i][j];
		}
		cout<<counter()<<endl;
	}
}
