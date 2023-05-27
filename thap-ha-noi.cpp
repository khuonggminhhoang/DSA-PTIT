#include<iostream>

using namespace std;

void HNtower(int n, char a, char b, char c){
	if(n==1) cout<<a<<" -> "<<c<<endl;
	else{
		HNtower(n-1, a,c,b);			// chuyen n-1 dia sang coc B
		cout<<a<<" -> "<<c<<endl;		// chuyen dia thu n sang coc C
		HNtower(n-1, b,a,c);			//chuyen n-1 dia sang coc C
	}
}

main(){
	int n;
	cin>>n;
	char a='A', b='B', c='C';
	HNtower(n,a,b,c);
}
