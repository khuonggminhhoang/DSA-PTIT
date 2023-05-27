#include<iostream>
#include<algorithm>

using namespace std;

// tim kiem tren mang da duoc sap xep
//tim kiem tam phan

int Ternary_search(int a[], int value, int start, int end){
	if(start > end) return -1;
	int mid1 = start + (end - start)/3;
	int mid2 = start + 2* (end - start)/3;
	if( a[mid1] == value ) return value;
	if( a[mid2] == value) return value;
	if( value < mid1){
		return Ternary_search(a,value, start, mid1-1);
	}
	if( value > mid2 ){
		return Ternary_search(a,value, mid2+1, end);
	}
	return Ternary_search(a,value, mid1, mid2);
}

main(){
	int n=10000,
		x=n;
	//cin>>n>>x;
	int a[n];
	for(int i=0; i<n; ++i) a[i]=i+1;
	sort(a,a+n);
	cout<<Ternary_search(a,x,0,n-1);
}

