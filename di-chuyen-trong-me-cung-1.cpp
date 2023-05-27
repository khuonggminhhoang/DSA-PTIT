#include<iostream>

using namespace std;

bool flag=false;
int a[1000][1000];
int n;

void Back_Track(int i, int j, string res){
	if( i==n || j==n || a[i][j] == 0) return ;
	if( i==n-1 && i==j){
		cout<<res<<" ";
		flag=true;
		return;
	}
	Back_Track(i+1, j, res + 'D');
	Back_Track(i, j+1, res + 'R');
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cin>>a[i][j];
		flag=false;		
		string res="";
		Back_Track(0,0,res);
		if(!flag) cout<<-1;
		cout<<endl;
	}
}
