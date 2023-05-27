#include<iostream>

using namespace std;

void print(int a[], int n){
	cout<< "[" ;
	for(int i=1; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<a[n]<<"] ";
}

void printArr(int a[], int n){
	int b[100];
	if(n>=1){
		for(int i=1; i<n; ++i)
			b[i]= a[i] + a[i+1];
			
		printArr(b,n-1);
		print(a,n);
	} 
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1; i<=n; ++i)
			cin>>a[i];
		printArr(a,n);
		cout<<endl;
	}
	
}
