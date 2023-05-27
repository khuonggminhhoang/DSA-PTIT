#include<iostream>

using namespace std;

void Quick_Sort(int a[], int left, int right){
	int pivot= a[ (left+right)/2 ];
	int l=left, r=right;
	
	while(l<r){
		while( a[l] < pivot) l++;
		while( a[r] > pivot) r--;
		swap(a[r], a[l]);
		l++;
		r--;	
	}
	if(left < r) Quick_Sort(a,left,r);
	if(l < right) Quick_Sort(a,l,right);
}


main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	Quick_Sort(a,0,n-1);
	for( auto x : a) cout<<x<<" ";
}

/*
9
13 21 15 14 12 9 14 7 6
*/
