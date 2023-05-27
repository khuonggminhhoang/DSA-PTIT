#include<iostream>

using namespace std;

int n,k,a[100], b[100];

void print(){
	for(int i=1; i<=n; ++i)
		if(a[i]==1) cout<<b[i]<<" ";
	cout<<endl;
}

bool next_bits(){
	int pos;
	for( pos=n; pos>=1; --pos)
		if(a[pos] == 0) break;
	
	for(int i=pos; i<=n; ++i)
		a[i]= 1- a[i];
		
	for(int i=1; i<=n; ++i)
		if(a[i] == 0 ) return false;
	return true;
}

bool check(){
	int sum=0;
	for(int i=1; i<=n; ++i)
		if(a[i] == 1) sum+=b[i];
	if(sum==k) return true;
	return false;
}

main(){
	cin>>n>>k;
	for(int i=1; i<=n; ++i)
		a[i]=0;
	for(int i=1; i<=n; ++i)
		cin>>b[i];
	bool flag=false;
	int count=0;
	while(!flag){
		if(check()){
			print();
			count++;
		}
		flag=next_bits();
	}
	if(check()) print();
	cout<<count<<endl;
}
