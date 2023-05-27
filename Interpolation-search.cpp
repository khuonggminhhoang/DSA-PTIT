#include<iostream>

using namespace std;

//tim kiem noi suy
// tim kiem tren mang da duoc sap xep
int interlationSearch(int a[], int n, int x){
	int low=0, hight=n-1, mid;
	
	while( a[low] <= x && x <= a[hight]){
		
		if( a[low] - a[hight] == 0) return (low + hight)/2;
		
		mid = low + (x- a[low] ) * (hight-low)/(a[hight] - a[low]);
		
		if( a[mid] < x) low=mid+1;
		else 
			if ( a[mid] > x) hight = mid-1;
		else 
			return mid;
	}
	if( a[low] == x) return low;
	return -1;
}

main(){
	int n=10000
		,x=n;
//	cin>>n>>x;
	int a[n];
	for(int i=0; i<n; ++i) a[i]=i+1;
	cout<<a[interlationSearch(a,n,x)];
}
