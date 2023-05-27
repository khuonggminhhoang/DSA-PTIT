#include<iostream>

using namespace std;

int n, a[100];

void print(){
	for(int i=1; i<=n; ++i)
		cout<<a[i];
	cout<<endl;
}

bool check(){
	if( a[1]==6 || a[n]==8) return false;
	
	for(int i=1; i<n; ++i)
		if( a[i] == a[i+1] && a[i] == 8) return false;
	
	for(int i=1; i<= n-3; ++i)
		if(a[i]== a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] && a[i] == 6) return false;
	return true;
}

bool next_bits(){
	int pos;
	for( pos= n; pos>=1; --pos)
		if(a[pos]==6) break;
	for(int i=pos; i<=n; ++i)
		if(a[i]==6) a[i]=8;
		else a[i]=6;
	
	for(int i=1; i<=n; ++i)
		if(a[i]==6) return false;
	return true; 
}

main(){
	cin>>n;
	for(int i=1; i<=n; ++i)
		a[i]=6;
	bool flag=false;
	while(!flag){
		if(check()) print();
		flag=next_bits();
	}
	if(check()) print();
}
