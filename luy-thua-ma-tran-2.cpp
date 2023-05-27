#include<iostream>

using namespace std;

const int mod = 1e9+7;
int n;
long long k;
long long a[10][10], b[10][10];

void Mul(long long x[10][10], long long y[10][10]){
	long long tmp[10][10];
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			long long res=0;
			for(int l = 0; l<n; ++l){
				res+= (x[i][l] * y[l][j])%mod;
				res%=mod;
			}
			tmp[i][j] = res;
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			x[i][j] = tmp[i][j];
		}
	}
}

void Pow(long long x[10][10], long long n){
	if(n==1) return ;
	Pow(x,n/2);
	Mul(x,x);
	if(n%2) Mul(x,b);
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j){
				cin>>a[i][j];
				b[i][j]=a[i][j];
			}
		Pow(a,k);	
		long long sum=0;
		for(int i=0; i<n; ++i){
			sum += a[i][n-1] % mod;
			sum%=mod;
		}
		cout<<sum<<endl;
	}
}
