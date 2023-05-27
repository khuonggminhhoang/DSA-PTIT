#include<iostream>
#include<cmath>

using namespace std;
bool visited[100];
int n, a[100];

void print(){
	for(int i=1; i<=n; ++i)
		cout<<a[i];
	cout<<endl;
}

bool check(){
	for(int i=1; i<n; ++i){
		if(abs(a[i+1]-a[i])==1) return false;
	}
	return true;
}

void Try(int i){
	for(int j=1; j<=n; ++j){
		if(!visited[j]){
			a[i]=j;
			visited[j]=1;
			if(i==n && check()) print();
			else Try(i+1);
			visited[j]=0;
		}
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		Try(1);
	}
}
