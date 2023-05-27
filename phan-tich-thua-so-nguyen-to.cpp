#include<iostream>

using namespace std;

void analyze_prime(int n)
{
	int index=2, count=0;
	while(n!=1)
	{
		if(n%index==0) 
		{
			count++;
			n/=index;
			if(n==1) cout<<index<<"("<<count<<") ";
		}
		else
		{
			if(count!=0) cout<<index<<"("<<count<<") ";
			index++;
			count=0;
		}
		
	}
}

main(){
	int t, dem=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<"Test "<<dem<<": ";
		analyze_prime(n);
		cout<<endl;
		dem++;
	}
}
