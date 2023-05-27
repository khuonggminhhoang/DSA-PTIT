#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

class Object{
	private:
		int num;
		int times;
	public:
		void print();		
		void setNum(int a);
		void setTimes(int t);
		int getNum();
		int getTimes();
};

void Object::print(){
	while(times--){
		cout<<num<<" ";
	}
}

void Object::setNum(int a){
	num = a;
}

void Object::setTimes(int t){
	times = t;
}

int Object::getNum(){
	return num;
}

int Object::getTimes(){
	return times;
}

bool cmp( Object First , Object Second){
	if( First.getTimes() > Second.getTimes() ) return true;	
	else if(First.getTimes() == Second.getTimes())
		if( First.getNum() < Second.getNum() ) return true;
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		set <int> st;
		for(int i=0; i<n; ++i) {
			cin>>a[i];
			st.insert(a[i]);
		}
		
		Object obj[st.size()];
		int index=0;
		for( auto x : st){
			int count=0;
			for(int i=0; i<n; ++i){
				if(x==a[i]) ++count;
			}
			obj[index].setNum(x);
			obj[index].setTimes(count);
			++index;
		}
		
		sort(obj, obj + st.size(), cmp);
		for(int i=0; i<st.size(); ++i){
			obj[i].print();
		}
		
		cout<<endl;
	}
}
