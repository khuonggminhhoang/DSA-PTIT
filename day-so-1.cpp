#include<iostream>

using namespace std;

void print(int a[], int n){
	cout<< "[" ;
	for(int i=1; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<a[n]<<"]\n";
}

void printArr( int a[], int n){
	if(n>=1){
		print(a,n);
		for(int i=1; i<n; ++i)
			a[i]+=a[i+1];
		printArr(a,n-1);
	}
}


main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=1; i<=n; ++i)
			cin>>a[i];
		printArr(a,n);
	}
	
}
