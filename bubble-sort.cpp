#include<iostream>

using namespace std;

void Bubble_Sort(int a[], int n){
	bool flag;
	for(int i=0; i<n-1; ++i){
		flag=false;
		for(int j=0; j<n-i-1; ++j)
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				flag=true;
			}
		
		if(!flag) return; 
	}
}

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n; ++i) cin>>a[i];
	Bubble_Sort(a,n);
	for(auto x:a) cout<<x<<" ";
}
