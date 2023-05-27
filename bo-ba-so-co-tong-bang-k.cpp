#include<iostream>
#include<algorithm>

using namespace std;

void solve(long long a[], long long n, long long sum){
	for(long long l=0; l<n-2; ++l){
		long long k=l+1,r=n-1;
		while(k<r){
			long long y=a[l] + a[k] + a[r];
			if(y == sum){
				cout<<"YES\n";
				return;
			}
			if(y > sum){
				r--;
				continue;
			}
			k++;
		}
	}
	cout<<"NO\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n, sum;
		cin>>n>>sum;
		long long a[n];
		for(auto &x : a) cin>>x;
		sort(a,a+n);
		solve(a,n,sum);
		
	}
}

/*
2
6 22
1 4 15 6 10 8
3 4
1 1 1

 

*/
