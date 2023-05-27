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

void solve(int a[], int n){
	int l=0, r=n-1;
	while(l<r){
		cout<<a[r]<<" "<< a[l]<< " ";
		l++;
		r--;
	}
	if(l==r) cout<<a[r];
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		Insertion_Sort(a,n);
		//for(int i=0; i<n; ++i) cout<<a[i]<<" ";
		solve(a,n);
		cout<<endl;
	}
}
