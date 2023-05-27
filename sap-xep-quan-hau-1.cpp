#include<iostream>
#include<cstring>
using namespace std;

int t, n,count;
int xuoi[100], nguoc[100], a[105];
//int x[100][100];

//void print(){
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=n; ++j){
//			cout<<x[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//}

void Try(int i){
	for(int j=1; j<=n; ++j){
		if( a[j] && xuoi[i-j+n] && nguoc[i+j-1]){
//			x[i][j]=1;
			a[j]=false;
			xuoi[i-j+n] = false;
			nguoc[i+j-1] = false;
			if(i==n) count++; // print();
			else Try(i+1);
//			x[i][j]=0;
			a[j]=true;
			xuoi[i-j+n] = true;
			nguoc[i+j-1] = true;
		}
	}
}

main(){
	cin>>t;
	while(t--){
		cin>>n;
		count=0;
		memset(xuoi, true, sizeof(xuoi));
		memset( nguoc, true, sizeof(nguoc));
		memset(a , true, sizeof(a));
		Try(1);
		cout<<count<<endl;

	}	
}
