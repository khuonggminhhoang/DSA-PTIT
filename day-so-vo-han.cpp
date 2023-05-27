#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

long long a[2][2], b[2][2];

void Mul(long long x[2][2],long long y[2][2]){
	long long tmp[2][2];
	for(int i=0; i<2; ++i){
		for(int j=0; j<2; ++j){
			long long res=0;
			for(int k=0; k<2; ++k){
				res+= x[i][k]*y[k][j] %mod;
				res%=mod;
			}
			tmp[i][j]=res;
		}
	}
	for(int i=0; i<2; ++i){
		for(int j=0; j<2; ++j){
			x[i][j]=tmp[i][j];
		}
	}
}

void Pow(long long x[2][2], long long k){
	if(k==1) return ;
	Pow(x,k/2);
	Mul(x,x);
	if(k%2) Mul(x,b);
}

main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		b[0][0] = a[0][0] = 0;
		a[0][1] = a[1][0] = a[1][1] =1;
		b[0][1] = b[1][0] = b[1][1] =1;
		Pow(a,n-1);
		cout<<a[1][1]<<endl;
	}
}
/*
 y tuong : dung ma tran fibonacci de tinh
			t
	[ 0 1]	  * [f0]		[ft]
	[ 1 1]		[f1]  =  	[ft+1]

*/
