#include<iostream>
#include<algorithm>

using namespace std;

int t,n,a[1003];

void print(){
	for(int i=1; i<=n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

void next_permutation(){
	int pos=0;
	for(int i=n; i>=2; --i)
		if(a[i] > a[i-1]){
			pos=i;
			break;
		}
		
	if(pos != 0){
		int k=n;
		while(k>pos-1 && a[pos-1] > a[k]) k--;
		swap(a[pos-1], a[k]);
	}
	sort(a+pos, a+n+1);
}

main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; ++i) cin>>a[i];
		next_permutation();
		print();
	}
}
