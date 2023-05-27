#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

long long Power(long long a, long long b){
	long long res=1;
	while(b>0){
		if(b%2){
			res = (res%mod * a%mod)%mod;
			b--;
		}
		else {
			a=(a%mod*a%mod)%mod;
			b/=2;
		}
	}
	return res;
}

int main(){
	long long a;
	long long b;
	while(1){
		cin>>a>>b;
		if(a==0 && b==0) return 0;
		long long ans = Power(a,b);
		cout<<ans<<endl;
	}
}
