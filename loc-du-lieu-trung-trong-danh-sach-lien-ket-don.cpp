#include<iostream>
#include<vector>

using namespace std;

main(){
	int n;
	cin>>n;
	vector <int> v;
	while(n--){
		int x;
		cin>>x;
		v.push_back(x);		
	}
	
	for(int i=0; i<v.size()-1; ++i){
		for(int j=i+1; j<v.size(); ++j){
			if( v[i] == v[j]){
				v.erase(v.begin() + j);
				--j;
			}
		}
	}
	
	for(auto x : v) cout<<x<<" ";
}
