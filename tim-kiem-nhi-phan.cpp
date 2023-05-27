#include<iostream>

using namespace std;

int BinarySearch(int a[],int n, int x){
	int m;
	int l=0, r=n-1;
	while(l<=r){
		m=(l+r)/2;
		if( a[m]==x) return m+1;
		if( a[m] < x) l=m+1;
		if(a[m] > x) r=m-1;
	}
	return 0;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int a[n];
		for(auto &y : a) cin>>y;
		BinarySearch(a,n,x)?cout<<BinarySearch(a,n,x)<<endl:cout<<"NO\n";
	}
}
