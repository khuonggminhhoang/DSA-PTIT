#include<iostream>
#include<cmath>

using namespace  std;

bool check(int n){
	if(n<2) return false;
	for(int i=2; i<=sqrt(n); ++i){
		if(n%i==0) return false;
	}
	return true;
}

void solve(int n){
	for(int i=2; i<= sqrt(n); ++i){
		if(check(i) && check(n-i)){
			cout<<i<<" "<<n-i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
}
