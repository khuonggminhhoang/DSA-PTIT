#include<iostream>

using namespace std;


bool check(int a[], int n){
	int r=n, l=1;
	while(l<r){
		if(a[l] != a[r]) return false;
		l++;
		r--;
	}
	return true;
	
}

bool sinh(int a[], int n){
	int pos;
	for(int i=n; i>=1; --i){
		if(a[i] == 6){
			pos=i;
			break;
		}
	}
	
	for(int i=pos; i<=n; ++i)
		if(a[i]==6) a[i]=8;
		else a[i]=6;
	
	for(int i=1; i<=n; ++i){
		if(a[i]==6) return false;
	}
	return true;
}

void print(int a[], int n){
	for(int i=1; i<=n; ++i)
		cout<<a[i];
	cout<<" ";
}

main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		for(int n=2; n<=x; n+=2){
			int a[n+1];
			bool flag = false;
			for(int i=1; i<=n; ++i) a[i]=6;
			while(!flag){
				if(check(a,n)) print(a,n);
				flag = sinh(a,n);
			}
			if(check(a,n)) print(a,n);
		}
	}
}
