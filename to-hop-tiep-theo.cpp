#include<iostream>

using namespace std;

int t, n,k, a[100], b[100];

void next_combination(){
	int pos=0;
	for(int i=k; i>=1; --i){
		if(a[i] < n-k+i){
			pos=i;
			break;
		}
	}
	
	if(pos != 0) {
		for(int i=1; i<pos; ++i)
			b[i]=a[i];
	
		b[pos]= a[pos]+1;
		
		for(int i=pos+1; i<=k; ++i){
			b[i]= b[pos] + (i-pos);
		}
	}
	else{
		for(int i=1; i<=k; ++i)
			b[i]=0;
	}
	
}

main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1; i<=k; ++i) cin>>a[i];
		next_combination();
		
		int count=0;
		for(int i=1; i<=k; ++i){
			int dem=0;
			for(int j=1; j<=k; ++j){
				if(b[j]!=a[i]) dem++;
			}
			if(dem==k) count++;
		}
		cout<<count<<endl;
	}
}
