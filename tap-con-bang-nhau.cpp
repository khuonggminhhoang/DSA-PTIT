//#include<iostream>
//
//using namespace std;
//
//int a[100];
//int n;
//int sum1, sum2;
//bool visited[100];
//bool flag;
//void Back_Track(int k){
//	if (flag) return;
//	for( int i=0; i<n; ++i){
//		if(!visited[i]){
//			sum1+=a[i];
//			visited[i]=true;
//			if(sum1==sum2){
//				flag=true;
//			}
//			if(k!=n-1) Back_Track(k+1);
//			sum1-=a[i];
//			visited[i]=false;
//		}
//	}
//}
//
//main(){
//	int t;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		sum1=0;
//		sum2=0;
//		flag=false;
//		for(int i=0; i<n; ++i) {
//			cin>>a[i];
//			sum2+=a[i];
//		}
//		if(sum2%2!=0) {
//			cout<<"NO\n";
//			continue;
//		}
//		sum2/=2;
//		for(int i=0; i<n; ++i) visited[i]=false;
//		Back_Track(0);
//		if(flag) cout<<"YES\n";
//		else cout<<"NO\n";
//	}
//
//}

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], sum=0;
		for(auto &x : a) {
			cin>>x;
			sum+=x;		
		}
		if(sum%2!=0) {
			cout<<"NO\n";
			continue;
		}
		sum/=2;
			
		int dp[sum+1]={0};
		dp[0]=1;
		int m=sum;
		for(int i=0; i<n;++i){
			while(m>=a[i]){
				if( dp[m-a[i] ]) dp[m]=1;
				--m;
			}
			m=sum;
		}
		if(dp[m]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
