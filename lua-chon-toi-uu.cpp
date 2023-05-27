#include<iostream>
#include<algorithm>
#include<vector>
#define test() int t; cin>>t; while(t--)

using namespace std;

struct Active{
	int timeStart, timeEnd;
};

bool cmp(Active a, Active b){
	return a.timeEnd < b.timeEnd;
}

main(){
	test(){
		int n;
		cin>>n;
		vector <Active> v;
		while(n--){
			int x,y;
			cin>>x>>y;
			Active a= {x,y};
			v.push_back(a);
		}
		sort(v.begin(), v.end(), cmp);
		int cnt=1;
		for(int i=0; i<v.size()-1; ++i){
			if(v[i].timeEnd <= v[i+1].timeStart ) ++cnt;
			else{
				v.erase(v.begin() + i+1);
				--i;
			}
		}
		cout<<cnt<<endl;
	}
}
