#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Active{
	int timeStart, timeEnd;
};

bool cmp(Active a, Active b){
	return a.timeEnd < b.timeEnd;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], b[n];
		for(auto &x : a ) cin>>x;
		for(auto &x : b ) cin>>x;
		vector <Active> act;
		for(int i=0; i<n; ++i){
			Active x = {a[i],b[i]};
			act.push_back(x);
		}
		sort(act.begin(), act.end(),cmp);
		int cnt=1;
		for(int i=0; i<act.size()-1; ++i){
			if(act[i].timeEnd <= act[i+1].timeStart ) ++cnt;
			else{
				act.erase(act.begin() + i+1);
				--i;
			}
		}
		cout<<cnt<<endl;
	}
}
