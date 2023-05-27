#include<iostream>

using namespace std;

int t, n;
char s[100];
void print(){
	for(int i=1; i<=n; ++i)
		cout<<s[i];
	cout<<" ";
}

bool sinh(){
	int pos;
	for(pos=n; pos>=1; --pos)
		if(s[pos] == 'A') break;
		
	for(int i=pos; i<=n; ++i){
		s[i] = ( s[i] == 'A' )?'B':'A';	
	}
	
	for(int i=1; i<=n; ++i)
		if(s[i]=='A') return false;
	return true;
}

main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; ++i)
			s[i]='A';
		bool flag=false;
		while(!flag){
			print();
			flag=sinh();
		}
		print();
		cout<<endl;
	}
}
