#include<iostream>

using namespace std;

bool binary_search_(int a[],int n, int x){
	int low=0, hight=n-1 ;
	while(low <= hight ){
		int mid= (low+hight)/2;
		if( x < a[mid]) hight = mid-1 ;
		else if ( x > a[mid]) low = mid+1;
		else return true;
	}
	return false;
}

main(){
	int n=10000,
		x=10000;
	
	int a[n];
	for(int i=0; i<n; ++i) a[i]=i+1;
	cout<<binary_search_(a,n,x);
}
