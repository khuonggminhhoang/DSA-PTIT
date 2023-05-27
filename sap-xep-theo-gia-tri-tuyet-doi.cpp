#include<iostream>
#include<map>
#include<cmath>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		multimap <int, int> mymap;
		while(n--){
			int a;
			cin>>a;
			mymap.insert( {abs(x-a),a});
		}
		for( auto it : mymap){
			cout<<it.second<<" ";
		}
		cout<<endl;
	}
				
}
