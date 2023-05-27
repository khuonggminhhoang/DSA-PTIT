#include<iostream>
#include<cstdlib>

using namespace std;

bool sequentialSearch(int a[], int n, int x){
	for(int i=0; i<n;++i)
		if(x == a[i]) return true;
	return false;
}

main(){
	int n=10000,x=10000; 
	int a[n];
	for(int i=0; i<n; ++i) a[i]=i+1;
	
//	for( auto x: a) cout<<x<<" ";
	cout<<sequentialSearch(a,n,x);
}
