#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], min, count=0;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n-1; ++i){
			min=i;
			for(int j=i+1; j<n; ++j)
				if(a[j] < a[min]) min=j;
			if(min!=i){
				 swap(a[min],a[i]);
				count++;
			}
		}
		cout<<count<<endl;
	}
	
}
