#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

typedef Node* node;

node makeNode(int data){
	node res = new Node;
	res->data = data;
	res->next = nullptr;
	res->prev = nullptr;
	return res;
}

void insert_head(node &head, node &tail, int data){
	node tmp = makeNode(data);
	if(head == nullptr){
		head = tmp;
		tail = tmp;
		return;
	}
	tmp->next = head;
	head->prev = tmp;
	head = tmp;		
}

void insert_tail(node &head, node &tail, int data){
	node tmp = makeNode(data);
	if( head == nullptr){
		head = tmp;
		tail = tmp;
		return;
	}
	tail->next = tmp;
	tmp->prev = tail;
	tail = tmp;
}

void forward_display(node head){
	node tmp = head;
	if(head = nullptr) return;
	while(tmp != nullptr){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

void reverse_display(node tail){
	node tmp = tail;
	if(tail == nullptr) return;
	while( tmp != nullptr){
		cout<<tmp->data<<" ";
		tmp = tmp->prev;
	}
}


main(){
	node head = nullptr;
	node tail = nullptr;
	for(int i=0; i<=10; i+=2) insert_head(head,tail,i);
	insert_tail(head,tail,1111);
	forward_display(head);
	cout<<endl;
	reverse_display(tail);
}
