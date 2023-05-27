#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n,k, a[10005];
vector <int> v;
set <int> st;

void print(){
	for(int i=1; i<=k; ++i)
		cout<<v[a[i]-1]<<" ";
	cout<<endl;
}

bool next_permutation(){
	int pos;
	for(pos = k; pos >=1; --pos)
		if( a[pos] < st.size()-k+pos) break;
		
	a[pos]+=1;
	for(int i=pos+1; i<=k; ++i)
		a[i]= a[pos] +(i-pos);
		
	for(int i=1; i<=k; ++i )
		if( a[i] != st.size()-k + i) return false;
	return true;
}


main(){
	cin>>n>>k;
	for(int i=1; i<=k ; ++i) a[i]=i;
	for(int i=1; i<=n; ++i){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(int x: st){
		v.push_back(x);
	}
		
	bool flag=false;
	while(!flag){
		print();
		flag= next_permutation();
	}
	print();
	
	
}
