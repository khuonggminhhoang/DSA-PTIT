#include<iostream>

using namespace std;

int jumpSearch(int a[], int n, int x){
	int d=3;
	int i=0, j=i+d;
	
	while( j<n && a[j] < x ){
		j+=d;
		i+=d;
	}
	
	if( j > n-1){
		j=n-1;
	}
	
	while( a[i] < x ){
		++i;
		if(i > n-1 || i>j){
			return -1;
		}
	}
	
	if(a[i]==x) return i;
	return -1;
}

main(){
	int n=10000,
		x=n;
	int a[n];
	for(int i=0; i<n; ++i) a[i]=i+1;
	cout<<jumpSearch(a,n,x);
}
