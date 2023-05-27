#include<iostream>
#include<algorithm>

using namespace std;

int binary_search_(int a[], int n, int x){
	int low=0, hight=n-1;
	while(low <= hight){
		int mid= (low + hight)/2;
		if( a[mid] < x) low=mid+1;
		else if(a[mid]>x) hight=mid-1;
		else return 1;
	}
	return -1;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		sort(a,a+n);
		cout<<binary_search_(a,n,k)<<endl;
	}
}
