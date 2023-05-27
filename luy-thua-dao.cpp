#include<iostream>
#include<string>

using namespace std;

const int mod = 1e9 + 7;

long long convert_number_reverse(string s){
	long long res=0;
	for(int i=s.size() -1 ; i>=0; --i ) res= 10*res + (s[i]-'0');
	return res;
}

long long Power(long long n, long long k){
	if(k==0) return 1;
	long long r = Power(n,k/2) % mod;
	if(k%2==0){
		return ((r%mod) * (r%mod))%mod;
	}
	else return (r*r)%mod * n%mod;
}

main(){
	int t;
	cin>>t;
	while(t--){
		long long num;
		cin>>num;
		string s;
		s=to_string(num);
		long long a, res;
		a= convert_number_reverse(s);
		res=Power(num,a);
		cout<<res<<endl;
	}
}
