#include<iostream>
#include<algorithm>

using namespace std;

int times,n, a[100];

void print(){
	for(int i=1; i<=n; ++i)
		cout<<a[i];
	cout<<" ";
}

bool sinh(){
	int t;
	for(t=n; t>=2; --t)
		if(a[t-1] > a[t]) break;
	
	int k=t;
	while(k<=n && a[t-1] > a[k]) k++;
	swap(a[t-1], a[k-1]);
	sort(a+t,a+n+1, greater<int>());  //greater<int>()
	for(int i=1; i<n; ++i)
		if(a[i] > a[i+1]) return false;
	return true;
}

main(){
	cin>>times;
	while(times--){
		cin>>n;
		for(int i=1; i<=n; ++i) a[i]=n-i+1;
		bool flag=false;
		//print();
		while(!flag){
			print();
			flag=sinh();
		}
		print();
		cout<<endl;
	}
}
