#include<iostream>

using namespace std;

long long UCLN( int a, int b){
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}

long long BCNN( int a, int b){
	return a*b/UCLN(a,b);
}

main(){
	int t;
	cin>>t;
	int a,b;
	while(t--){
		cin>>a>>b;
		cout<<UCLN(a,b)<<" "<< BCNN(a,b)<<endl;
	}
}
