#include<iostream>
#include<algorithm>

using namespace std;

int cnt[5];

int first_pos(int b[], int n, int x){
	int l=0, r=n-1, m;
	int res=-1;
	while(l<=r){
		m=(l+r)/2;
		if(b[m] > x){
			res=m;
			r=m-1;
		}
		else l=m+1;
	}
	return res;
}

long long count(int b[], int m, int x){
	if(x==0) return 0;
	if(x==1) return cnt[0];
	
	long long res= cnt[0] + cnt[1];
	int l = first_pos(b,m,x);
	if(l!=-1){
		res += m- l ; // m-1 -l + 1
	}
	
	if(x==2) res-= (cnt[3] + cnt[4]);
	
	if(x==3) res+= cnt[2];
	return res;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(auto &x : a) cin>>x;
		for(auto &x : b){
			cin>>x;
			if(x <= 4){
				cnt[x]++;
			}
		}
		sort(b,b+m);
		long long ans=0;
		for(auto x : a){
			ans+= count(b,m,x);
		}
	
		cout<<ans<<endl;
		for(auto &x:cnt) x=0;
	}
}
