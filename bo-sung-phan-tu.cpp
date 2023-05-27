#include<iostream>
#include<set>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		vector <int> v;
		set<int> s;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i){
			cin>>a[i];
			s.insert(a[i]);
		}
		for( int x : s) v.push_back(x);
		cout<< v[s.size()-1] - v[0] + 1 - s.size()<<endl;
	}
}

