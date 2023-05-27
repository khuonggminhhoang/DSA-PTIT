#include<iostream>

using namespace std;

int m,n,i,j, a[105][105],count;

void Try(int i, int j){
	if(i==n || j==m ) return;
	if(i == n-1 && j == m-1 ) count++;
	
	Try(i+1,j);
	Try(i, j+1);
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				cin>>a[i][j];
		count=0;
		Try(0,0);
		cout<<count<<endl;	
	}
}
