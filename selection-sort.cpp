#include<iostream>

using namespace std;

void selection_sort(int a[], int n){
	int min;
	for(int i=0; i<n-1; ++i){
		min=i;
		for(int j=i+1; j<n; ++j){
			if(a[min] > a[j]) min=j;
		}
		swap(a[min], a[i]);
	}
}

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	selection_sort(a,n);
	for(auto x:a) cout<<x<<" ";
	cout<<endl;
}


