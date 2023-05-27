#include<iostream>

using namespace std;

void bubbleSort(int a[], int n){
	bool flag;
	int count=1;
	for(int i=0; i<n-1; ++i){
		flag=false;
		for(int j=0; j<n-i-1; ++j){
			if(a[j]> a[j+1]){
				swap(a[j], a[j+1]);
				flag=true;
			}
			
		}
		if(flag) {
			cout<<"Buoc "<<count<<": ";
			for(int i=0; i<n; ++i) cout<<a[i]<<" ";
			count++;
			cout<<endl;
		}
	}
}

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	bubbleSort(a,n);
}
