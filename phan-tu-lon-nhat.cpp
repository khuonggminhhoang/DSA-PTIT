#include<iostream>

using namespace std;

void Insertion_Sort(int a[], int n){
	int pos,x;
	for(int i=1; i<n; ++i){
		x=a[i];
		pos=i-1;
		
		while( pos>=0 && a[pos] > x){
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1] = x;
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		Insertion_Sort(a,n);
		int index=n-1;
		while(k--){
			cout<<a[index]<< " ";
			--index;
		}
		cout<<endl;
	}
}
