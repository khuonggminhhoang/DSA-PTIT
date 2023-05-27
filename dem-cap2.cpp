#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		vector <long long > v;
		while(n--){
			long long x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		long long ans=0;
		for(int i=0; i<v.size()-1 ; ++i){
			ans+= lower_bound(v.begin()+ i, v.end(), v[i] + k) - v.begin() - i - 1;
		}
		cout<<ans<<endl;
	}
}
