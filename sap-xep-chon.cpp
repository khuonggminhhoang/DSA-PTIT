#include<iostream>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	
	for(int i=0; i<n-1; ++i){
		int min=i;
		for(int j=i+1; j<n; ++j){
			if(a[j] < a[min]){
				min=j;
			}
		}
		swap(a[min],a[i]);
		
		cout<<"Buoc "<< i+1 << ": ";
		for(int i=0; i<n; ++i)	
			cout<<a[i]<<" ";
		cout<<endl;
	}
}
