#include<iostream>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n], L[n];
	for( auto &x : a) cin>>x;
	for ( auto &x : L) x=1;
	for(int i=1; i<n; ++i){
		for( int j=0; j<i; ++j){
			if(a[j] < a[i]) L[i]= max(L[i], L[j]+1);  //tìm phan tu tai vi tri i xem														//
		}											  //co the chen a[i] vao lam phan tu cua day con phia trc ko
	}
	for(int i=0; i<n-1; ++i){
		if(L[i] > L[i+1]) swap(L[i], L[i+1]);
	}
	cout<<L[n-1];
}
