#include<iostream>

using namespace std;

void print(int a[], int k){
	for(int i=1; i<=k; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

void sinh(int a[], int n, int k){
	int pos=0;
	for(int i=k; i>=1; --i){
		if(a[i] < n-k+i){
			pos=i;
			break;
		}
	}
	if(pos!=0){
		a[pos]+=1;
		for(int i=pos+1; i<=k; ++i)
			a[i]=a[pos] + (i-pos);
	}
	else
		for(int i=1; i<=k; ++i) a[i]=i; 
	
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=1;i<=k; ++i) cin>>a[i];
		sinh(a,n,k);
		print(a,k);
		
	}
}
