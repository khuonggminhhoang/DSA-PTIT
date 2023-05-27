#include<iostream>

using namespace std;

void merge(int a[], int l, int m, int r){
	int n1= m-l +1;
	int n2= r-m;
	int x[n1], y[n2];
	
	for(int i=0; i<n1; ++i)
		x[i] = a[l+i];
	for(int i=0; i<n2; ++i)
		y[i] = a[m+1+i];
		
	int i=0, j=0;
	while( i < n1 && j < n2){
		a[l++] = (x[i] < y[j]) ? x[i++] : y[j++];
	}
	while(i<n1){
		a[l++] = x[i++];
	}
	while(j<n2){
		a[l++] = y[j++];
	}
	
}

void mergeSort(int a[], int l, int r){
	if(l>=r) return ;
	int m= (l+r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n; 
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		mergeSort(a,0,n-1);
		for(auto x : a) cout<<x <<" ";
		cout<<endl;
	}
}
