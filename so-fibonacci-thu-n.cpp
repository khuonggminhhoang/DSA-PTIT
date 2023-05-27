#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

struct Matrix{
	long long a00, a01, a10, a11;
};

Matrix Mul( Matrix x, Matrix y){
	Matrix res;
	res.a00 = ((x.a00*y.a00)%mod + (x.a01*y.a10)%mod)%mod;
	res.a01 = ((x.a00*y.a01)%mod + (x.a01*y.a11)%mod)%mod;
	res.a10 = ((x.a10*y.a00)%mod + (x.a11*y.a10)%mod)%mod;
	res.a11 = ((x.a10*y.a01)%mod + (x.a11*y.a11)%mod)%mod;
	return res;
}

Matrix Pow(Matrix x, int n){
	if(n==1) return x;
	Matrix P = Pow(x,n/2);
	Matrix ans = Mul(P,P);
	if(n%2) return Mul(ans,x);
	return ans;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0 || n==1){
			cout<<n<<endl;
			continue;
		}
		Matrix x = {0,1,1,1};
		Matrix y = x;
		Matrix ans = Pow(x,n-1);
		cout<<ans.a11<<endl;
	}
}
