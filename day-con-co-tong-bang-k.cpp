#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,k,i, a[1005], b[1005];
bool flag;

void print(){	
	vector <int> v;
	for(i=1; i<=n; ++i)
		if(b[i]==0) v.push_back(a[i]);
	
	cout<<"[";
	for(int i=0; i<v.size()-1; ++i)
		cout<<v[i]<<" ";
	cout<<v[v.size()-1]<<"] ";
}

bool check(){
	int sum=0;
	for(int i=1; i<=n; ++i)
		if(b[i]==0) sum+=a[i];
	if(sum==k) return true;
	return false;
}

void Try(int i){
	for(int j=0; j<=1; ++j){
		b[i]=j;
		if(i==n ){
			if(check()){
				print();
				flag=true;
			}
		}
		else Try(i+1);
	}
}

main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1; i<=n; ++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		flag = false;
		Try(1);
		if(flag == false) cout<<-1;
		cout<<endl;
	}
}
