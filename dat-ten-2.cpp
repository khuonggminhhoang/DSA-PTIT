#include<iostream>

using namespace std;

int t,n,k,a[100];

void print(){
	for(int i=1; i<=k; ++i)
		cout<< (char) (a[i] + 'A' -1);
	cout<<endl;	
}

bool next_string(){
	int pos;
	for(pos=k; pos>=1; --pos)
		if(a[pos] < n-k+pos) break;
	
	a[pos]+=1;
	for(int i=pos+1; i <= k ; ++i )
		a[i] = a[pos] + (i-pos);
	
	for(int i=1; i<=k; ++i)
		if(a[i] != n-k+i) return false;
	return true;
}

main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		bool flag=false;
		for(int i=1; i<=k; ++i)
			a[i]=i;
		while(!flag){
			print();
			flag=next_string();
		}
		print();
	}
}
