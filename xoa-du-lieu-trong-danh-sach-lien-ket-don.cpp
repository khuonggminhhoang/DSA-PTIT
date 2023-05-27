#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

typedef Node* node;

node makeNode(int data){
	node res = new Node();
	res->data = data;
	res->next = nullptr;
	return res;
}

void insert(node &a, int data){
	node tmp = makeNode(data);
	if(a==nullptr) a = tmp;
	else{
		node p = a;
		while(p->next != nullptr){
			p = p->next;
		}
		p->next = tmp;
	}
}

void erase(node &a, int x){
	if(a->next == NULL && a->data == x) {
		a= nullptr;
		return;
	} 
	node pre = new Node;
	node cur = new Node;
	while(a->data == x){
		a = a->next;
	}
	cur = a;
	pre = a;
	while(cur != nullptr){
		if(cur->data == x){
			pre->next = cur->next;
			cur = cur->next;
			continue;
		}
		pre = cur;
		cur = cur->next;
	}
}

void display(node a){
	while(a != nullptr){
		cout<<a->data<<" ";
		a = a->next;
	}
}

main(){
	int n;
	cin>>n;
	node first = nullptr;
	while(n--){
		int x;
		cin>>x;
		insert(first,x);
	}
	int x;
	cin>>x;
	erase(first,x);
	display(first);

}
