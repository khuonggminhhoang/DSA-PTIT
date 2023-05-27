#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		
		for(int i=0; i<n; ++i) cin>>a[i];
		
		int b[k], l=0, r=k-1;
		while( r <= n-1){
			int index=0;
			for(int i=l ; i<=r; ++i) b[index++]=a[i];
			
			for(int i=0; i<=k-2; ++i){
				if(b[i] > b[i+1]) swap(b[i],b[i+1]);  // dua phan tu lown nhat ve cuoi day cua mang b
			}
			
			cout<<b[k-1]<<" ";
			l++;
			r++;
		}
		cout<<endl;
	}
}
