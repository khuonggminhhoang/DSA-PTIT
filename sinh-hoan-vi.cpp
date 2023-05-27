#include<iostream>
#include<algorithm>

using namespace std;
int t,n,a[100];

void result(){
	for(int i=1; i<=n; ++i)
		cout<<a[i];
	cout<<" ";
}

bool sinh(){
	int pos=0;
	for(int i=n ; i>=2; --i)
		if(a[i] > a[i-1]){
			pos=i;
			break;
		}
		
	int k=n;
	while(a[pos-1] > a[k]) k--; //tim phan tu nho nhat lon hon a[pos-1]
	
	swap(a[k], a[pos-1]);
	sort(a+pos, a+n+1);
	for(int i=1; i<n; ++i)
		if(a[i] < a[i+1]) return false;
	return true;
}

main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; ++i) a[i]=i;
		bool flag=false;
		while(!flag){
			result();
			flag=sinh();
		}
		if(n!=1)
			result();
		cout<<endl;
	}
}
