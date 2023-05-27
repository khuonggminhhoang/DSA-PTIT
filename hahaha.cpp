#include<iostream>

using namespace std;
		

void print(int a[], int n){
	for(int i=1; i<=n; ++i)
		if(a[i]==1) cout<<'H';
		else cout<<'A';
	cout<<endl;
}

bool check(int a[], int n){
	if(a[1]==0 || a[n]==1) return false;
	for(int i=1; i<=n-1; ++i)
		if(a[i] == a[i+1] && a[i]==1) return false;
	return true;	
}

bool next_bits(int a[], int n){
	int pos;
	for( pos=n; pos>=1; --pos)
		if(a[pos]==0) break;
	
	for(int i=pos; i<=n; ++i)
		a[i]= 1-a[i];
	
	for(int i=1; i<=n; ++i)
		if(a[i]==0) return false;
	return true;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100];
		for(int i=1; i<=n; ++i)
			a[i]=0;
		bool flag=false;
		while(!flag){
			if(check(a,n)) print(a,n);
			flag=next_bits(a,n);
		}
		if(check(a,n)) print(a,n);
	}
}
