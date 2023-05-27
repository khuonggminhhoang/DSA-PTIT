#include<iostream>

using namespace std;

int binarySearch( int a[], int x, int low, int hight){
	int mid;
	while(low <= hight){
		mid= (low + hight)/2;
		if( x < a[mid]) hight= mid-1;
		else if( x > a[mid]) low = mid +1;
		else return mid;
	}
	return 0;
}

int Search( int a[], int n, int x){
	int index=n-1;
	for(int i=0; i<n-1; ++i){
		if( a[i] > a[i+1]){
			index=i;
			break;
		}
	}
	
	int a1 = binarySearch(a,x,0,index)+1;
	int b = binarySearch(a,x,index+1,n-1)+1;
	if(a1!=1) return a1;
	return b;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		
		cout<< Search(a,n,x)<<endl;
		
		
	}
}
